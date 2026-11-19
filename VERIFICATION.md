# Verification record

## Environment of the pinned run (2026-11-19)

- macOS 26.6.2, x86_64, one core, run under `nice`.
- Apple clang 21.0.0, used as `c++ -std=c++17 -O2`.
- Ruby 2.6.10 (the system Ruby).
- pdfTeX 3.141592653-2.6-1.40.22 (TeX Live 2021).

The programs need no network and no precomputed tables. Their SHA-256 hashes
are in [MANIFEST.sha256](MANIFEST.sha256).

## Commands

```sh
make verify CXX=c++ RUBY=ruby
make paper
```

`make verify` runs [code/run-certificates.sh](code/run-certificates.sh). It
writes three outputs to `build/certificates/` and compares each byte for byte
with its pinned copy in [evidence/](evidence/), printing one `MATCH` line per
file. It fails on any mismatch, or if the number of outputs differs. The total
running time is under ten seconds, most of it compilation.

## What each certificate checks

| Paper step | Program | Pinned output |
|---|---|---|
| Theorem 2 and Section 3. For both certificates at 311 and a control at 23, the program checks: <ul><li>that the generator is primitive;</li><li>that each line has two prescribed rows;</li><li>the completion rule;</li><li>that every column is a signed Walsh vector;</li><li>the $T$ sums $(p,0,0,0)$;</li><li>the energy $2p$ at all $p+1$ projective frequencies;</li><li>the product spectrum with the nine-point factor.</li></ul>A control with both signs flipped in one column fails at the energy test. | `check-certificates.rb` | `certificates.txt` |
| Theorem 1. The program builds the four sign functions of the first certificate on $\mathbb F_{311}^2\times\mathbb F_3^2$ and counts their sums (933 each) and their summed periodic autocorrelations: 3481956 at the zero shift and 0 at every other shift. 5625 shift representatives cover all 870489 shifts, since multiplication by a nonzero square in $\mathbb F_{311}$ fixes the functions. | `correlations.cpp` | `correlations.txt` |
| Table 2 and Theorem 7. For each of the five primes, the program checks the generator, the folded period $(a,b,c,d,0,d,-c,b)$ and the eight energies $2p$. | `periods.cpp` | `periods.txt` |

`correlations.cpp` works from the sign functions themselves and shares no code
with `check-certificates.rb`, which works with character sums.

## Paper build

`make paper` runs pdfLaTeX three times with a fixed `SOURCE_DATE_EPOCH` and
fails on any warning, overfull box or undefined reference.
