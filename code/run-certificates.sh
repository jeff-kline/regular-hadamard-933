#!/bin/sh
# Run every certificate and write its output to the directory given as $1.
# Environment: CXX (C++17 compiler), RUBY (Ruby interpreter).
# A few seconds on one core.
set -eu
out=${1:?output directory}
CXX=${CXX:-c++}
RUBY=${RUBY:-ruby}
mkdir -p "$out/bin"
"$CXX" -std=c++17 -O2 -o "$out/bin/correlations" code/correlations.cpp
"$CXX" -std=c++17 -O2 -o "$out/bin/periods" code/periods.cpp

# 1. Theorem 2 conditions at every projective frequency: both certificates at
#    311 (Section 3) and a control at 23.
"$RUBY" code/check-certificates.rb > "$out/certificates.txt"

# 2. Theorem 1: the four sign functions on F_311^2 x F_3^2, their sums and
#    their summed periodic autocorrelations at every shift.
"$out/bin/correlations" > "$out/correlations.txt"

# 3. Table 2: generators, folded period sums and the eight energies at
#    each of the five primes.
"$out/bin/periods" > "$out/periods.txt"
