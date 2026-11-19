// c++ -std=c++17 -O2 code/correlations.cpp -o correlations (see code/run-certificates.sh)
// Independent integer correlation check on F_311^2 x F_3^2.
#include <array>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

constexpr int p = 311;
using Four = std::array<int,4>;
using Mask = std::array<std::string,4>;
constexpr std::array<Four,4> walsh = {{{1,1,1,1},{1,-1,1,-1},{1,1,-1,-1},{1,-1,-1,1}}};

int label(const Four& signs) {
    for (int k=0;k<4;++k) {
        for (int s : {1,-1}) {
            bool match=true;
            for (int i=0;i<4;++i) match &= signs[i]==s*walsh[k][i];
            if (match) return 2*k+(s==-1);
        }
    }
    throw std::runtime_error("sign vector has no Walsh label");
}

std::vector<int> make_labels() {
    const Mask masks={"0++--0+0","0000+-0-","+-0-0000","+0-00++-"};
    std::array<bool,p> square{};
    for (int t=1;t<p;++t) square[t*t%p]=true;
    std::vector<int> labels(p*p,-1);
    labels[0]=0;
    int u=1,v=0;
    for (int j=0;j<=p;++j) {
        const int cycle=j/8, pos=j%8, phase=cycle%2 ? -1 : 1;
        Four a{},b{};
        int first=-1, product=1;
        for (int i=0;i<4;++i) {
            char c=masks[i][pos];
            if (c!='0') {
                a[i]=(c=='+' ? phase : -phase);
                product*=a[i];
            }
        }
        for (int i=0;i<4;++i) {
            if (a[i]) continue;
            const int x=cycle==38 ? (pos<2 ? -1 : 1) : phase;
            b[i]=first<0 ? x : x*product;
            first=i;
        }
        for (int t=1;t<p;++t) {
            Four signs{};
            for (int i=0;i<4;++i) signs[i]=b[i]+(square[t] ? a[i] : -a[i]);
            int& entry=labels[(t*u%p)*p+t*v%p];
            if (entry!=-1) throw std::runtime_error("duplicate point");
            entry=label(signs);
        }
        int next=(u-4*v+4*p)%p;
        v=(4*u+v)%p;
        u=next;
    }
    for (int t:labels) if (t<0) throw std::runtime_error("missing point");
    return labels;
}

// Four product signs at (x,w) computed from the label of x.
Four product_signs(int code,int w) {
    const int x=w/3,y=w%3;
    const int a=y==0 ? -1:1, b=y==x ? -1:1, c=y==(2*x)%3 ? -1:1, d=x==0 ? -1:1;
    const std::array<Four,4> columns={{{a,b,c,d},{-b,a,d,-c},{-c,-d,a,b},{-d,c,-b,a}}};
    Four signs=columns[code/2];
    if (code%2) for (int& v:signs) v=-v;
    return signs;
}

int main() {
    auto labels=make_labels();
    Four sums{};
    for (int code:labels) for (int w=0;w<9;++w) {
        auto signs=product_signs(code,w);
        for (int i=0;i<4;++i) sums[i]+=signs[i];
    }
    if (sums!=Four{933,933,933,933}) throw std::runtime_error("block sums");

    using Counts=std::array<std::array<int,8>,8>;
    std::array<Counts,9> local{};
    for (int v=0;v<9;++v) for (int w=0;w<9;++w) {
        int other=3*((v/3+w/3)%3)+(v%3+w%3)%3;
        for (int a=0;a<8;++a) for (int b=0;b<8;++b) {
            auto left=product_signs(a,w), right=product_signs(b,other);
            for (int i=0;i<4;++i) local[v][a][b]+=left[i]*right[i];
        }
    }

    // Every nonzero vector is a square multiple of one of these shifts.
    // The nonsquare -1 supplies the other representative on each line.
    std::vector<std::pair<int,int>> shifts={{0,0},{0,1},{0,p-1}};
    for (int slope=0;slope<p;++slope) {
        shifts.emplace_back(1,slope);
        shifts.emplace_back(p-1,(p-slope)%p);
    }
    for (auto [dx,dy]:shifts) {
        Counts pairs{};
        for (int x=0;x<p;++x) {
            int src=x*p, dest=(x+dx)%p*p, yy=dy;
            for (int y=0;y<p;++y) {
                ++pairs[labels[src+y]][labels[dest+yy]];
                if (++yy==p) yy=0;
            }
        }
        for (int v=0;v<9;++v) {
            int correlation=0;
            for (int a=0;a<8;++a) for (int b=0;b<8;++b)
                correlation+=pairs[a][b]*local[v][a][b];
            int expected=dx==0 && dy==0 && v==0 ? 4*933*933 : 0;
            if (correlation!=expected) throw std::runtime_error("failed autocorrelation");
        }
    }
    std::cout<<"Four block sums 933; "<<9*shifts.size()
             <<" shift representatives exhaust 870489 shifts; peak 3481956, off-peak zero.\n";
}
