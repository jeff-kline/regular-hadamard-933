// c++ -std=c++17 -O2 code/periods.cpp -o periods (see code/run-certificates.sh)
// With the fixed certificates below, field products fit in signed 64 bits.
#include <array>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string_view>
#include <utility>
#include <vector>

using Integer = std::int64_t;
using Point = std::pair<Integer,Integer>;
using Period = std::array<Integer,8>;

struct Certificate {
    Integer p;
    Point generator;
    std::array<Integer,4> coordinates;
};

Point multiply(Point u, Point v, Integer p) {
    return {(u.first*v.first - u.second*v.second + p*p) % p,
            (u.first*v.second + u.second*v.first) % p};
}

Point power(Point z, Integer n, Integer p) {
    Point result{1,0};
    while (n>0) {
        if (n%2) result=multiply(result,z,p);
        z=multiply(z,z,p);
        n/=2;
    }
    return result;
}

std::vector<Integer> prime_factors(Integer n) {
    std::vector<Integer> factors;
    for (Integer j=2; j*j<=n; ++j) {
        if (n%j) continue;
        factors.push_back(j);
        do { n/=j; } while (n%j==0);
    }
    if (n>1) factors.push_back(n);
    return factors;
}

void check(const Certificate& input) {
    const auto [p,z,coordinates]=input;
    const auto [a,b,c,d]=coordinates;
    if (prime_factors(p)!=std::vector<Integer>{p} || p%16!=7)
        throw std::runtime_error("field size");
    const Integer order=p*p-1;
    const Point one{1,0};
    if (power(z,order,p)!=one) throw std::runtime_error("field order");
    for (Integer n : {p-1,p+1})
        for (Integer prime : prime_factors(n))
            if (power(z,order/prime,p)==one)
                throw std::runtime_error("nonprimitive generator");

    std::vector<std::int8_t> character(p,-1);
    character[0]=0;
    for (Integer s=1;s<=p/2;++s) character[s*s%p]=1;
    Period w{};
    Point v=one;
    for (Integer j=0;j<=p;++j) {
        w[j%8]+=(j%16<8 ? 1 : -1)*character[v.first];
        v=multiply(v,z,p);
    }
    if (w!=Period{a,b,c,d,0,d,-c,b}) throw std::runtime_error("folded period");
    if (a*a+2*(b*b+c*c+d*d)!=p || 2*a*c-b*b+2*b*d+d*d!=0 ||
        c*(b-d)-a*(b+c)!=0) throw std::runtime_error("quadratic equations");

    const std::array<std::string_view,4> masks={
        "0++--0+0","0000+-0-","+-0-0000","+0-00++-"
    };
    for (int m=0;m<8;++m) {
        Integer energy=0;
        for (auto row:masks) {
            Integer sum=0;
            for (int j=0;j<8;++j) {
                int coeff=row[j]=='0' ? 0 : (row[j]=='+' ? 1 : -1);
                sum+=coeff*(m+j<8 ? 1 : -1)*w[(m+j)%8];
            }
            energy+=sum*sum;
        }
        if (energy!=2*p) throw std::runtime_error("line energy");
    }
    std::cout<<"p="<<p<<", regular parameter "<<3*p<<", order "<<36*p*p<<"\n";
}

int main() {
    for (auto input : std::array<Certificate,5>{{
        {7,{1,2},{1,1,1,-1}},
        {23,{1,2},{-1,3,-1,1}},
        {311,{1,4},{7,-1,-7,-9}},
        {6263,{2869,1599},{63,3,-7,-33}},
        {63258551,{1,14},{-2873,4719,-2057,1001}}
    }}) check(input);
}
