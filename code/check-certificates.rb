# Run from the repository root: ruby code/check-certificates.rb. All checks use exact integers.
require 'prime'

WALSH = [[1,1,1,1], [1,-1,1,-1], [1,1,-1,-1], [1,-1,-1,1]].freeze
MASKS = %w[0++--0+0 0000+-0- +-0-0000 +0-00++-].freeze
def mul(z, w, p)
  [(z[0]*w[0] - z[1]*w[1]) % p, (z[0]*w[1] + z[1]*w[0]) % p]
end

def power(z, n, p)
  r = [1,0]
  while n.positive?
    r = mul(r, z, p) if n.odd?
    z = mul(z, z, p)
    n /= 2
  end
  r
end

def projection(rows, weights)
  rows.map { |r| r.zip(weights).sum { |x,y| x*y } }
end

def check(p, z, masks, fill)
  raise 'field or period' unless p.prime? && p % 16 == 7
  order = p*p-1
  raise 'generator' unless power(z, order, p) == [1,0] &&
    order.prime_division.all? { |r,_| power(z, order/r, p) != [1,0] }
  eta = Array.new(p,-1)
  eta[0] = 0
  (1...p).each { |x| eta[x*x % p] = 1 }

  lines = []
  odd = Array.new(4) { [] }
  even = Array.new(4) { [] }
  t_sums = [1,0,0,0] # Sign column at the origin is ++++.
  v = [1,0]
  (0..p).each do |j|
    lines << v
    v = mul(z,v,p)
    cycle, pos = j.divmod(8)
    a = masks.map { |s| {'+'=>1, '-'=>-1, '0'=>0}.fetch(s[pos]) * (-1)**cycle }
    u, w = (0..3).select { |i| a[i].zero? }
    raise 'support' unless a.count(0) == 2
    x = cycle == (p+1)/8-1 ? (-1)**fill[pos] : (-1)**cycle
    b = [0]*4
    b[u] = x
    b[w] = x * a.reject(&:zero?).inject(:*)
    4.times { |i| odd[i] << a[i]; even[i] << b[i] }
    [-1,1].each do |scalar_class|
      s = (0..3).map { |i| a[i]*scalar_class + b[i] }
      t4 = projection(WALSH, s)
      raise 'Walsh support' unless t4.map(&:abs).sort == [0,0,0,4]
      4.times { |i| t_sums[i] += (p-1)/2 * (t4[i]/4) }
    end
  end
  raise 'principal frequency' unless even.map(&:sum) == [1]*4 && t_sums == [p,0,0,0]

  # Ordinary dot-product frequencies (1,m), (0,1) independently of the generator.
  # Store exact real and Gauss-sum coefficients of 4*T at each frequency.
  spectra = [[[4*p,0,0,0], [0]*4]]
  (lines.size).times do |m|
    h = lines.map { |u,vv| eta[(m == p ? vv : u+m*vv) % p] }
    raise 'kernel' unless h.count(0) == 1
    k = h.index(0)
    d = projection(odd,h)
    raise "line energy #{m}" unless d.sum { |v1| v1*v1 } == 2*p
    spectra << [projection(WALSH, even.map { |row| p*row[k] }), projection(WALSH,d)]
  end

  # Left quaternion multiplication, first column (a,b,c,d).
  quaternion = lambda do |a,b,c,d|
    [[a,-b,-c,-d], [b,a,-d,c], [c,d,a,-b], [d,-c,b,a]]
  end
  # Compute all nine real Fourier spectra of the four signs on F_3^2.
  points = [0,1,2].product([0,1,2])
  partners = points.map do |h,k|
    coeff = (0..3).map do |j|
      buckets = [0]*3
      points.each do |x,y|
        on_line = j == 3 ? x.zero? : (y-j*x) % 3 == 0
        buckets[(h*x+k*y)%3] += on_line ? -1 : 1
      end
      raise 'non-real partner' unless buckets[1] == buckets[2]
      buckets[0] - buckets[1]
    end
    raise 'partner energy' unless coeff.sum { |v1| v1*v1 } == 36
    quaternion.call(*coeff)
  end
  spectra.each do |real, imag|
    partners.each do |mat|
      r, g = projection(mat,real), projection(mat,imag)
      energy = r.sum { |v1| v1*v1 } + p*g.sum { |v1| v1*v1 }
      raise 'product spectrum' unless energy == 16*4*(3*p)**2
    end
  end
  raise 'product row sums' unless projection(partners.first,t_sums) == [3*p]*4
  puts "p=#{p}, z=#{z.inspect}, #{p+1} projective frequencies, T sums #{t_sums.inspect}, regular order #{4*(3*p)**2}"
end

check(23, [1,2], MASKS, 3)
check(311, [1,4], MASKS, 3)
# The half-line supports of the published order-311 example, with the first
# odd row reflected and the whole lines reassigned.
check(311, [201,121], %w[++0+0000 -0+00+-- 0000--0- 0-++-0+0], 38)

# Negative control: flip both prescribed signs in column 1. Products and row
# sums are unchanged, so only the Fourier energy test can catch it.
begin
  check(311, [1,4], %w[0-+--0+0 0000+-0- ++0-0000 +0-00++-], 3)
  raise 'control passed'
rescue RuntimeError => e
  raise if e.message == 'control passed'
  puts "control: p=311 with one column of signs flipped fails as required (#{e.message})"
end
