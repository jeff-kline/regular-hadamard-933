# A regular Hadamard matrix of order 4·933²

Jeffery Kline

**Status: draft.** This repository is being prepared for release under the
project's
[public research standard](https://jeff-kline.github.io/posts/research-program/index.html).
No DOI exists yet.

The paper is [paper/main.pdf](paper/main.pdf); its source is
[paper/main.tex](paper/main.tex).

## Introduction

A Hadamard matrix is *regular* if all its row and column sums are equal. Its
order is then $4k^2$ for an integer $k$, the Menon parameter, and the common
sum is $2k$. Regular Hadamard matrices are conjectured to exist for every $k$.

This paper constructs a regular Hadamard matrix of order
$4\cdot933^2=3481956$, with every row and column sum equal to 1866. The
parameter $933=3\cdot311$ appears among the undecided cases in the lists of
Xia, Xia and Seberry (2007) and Crnković (2018).

Leung, Ma and Schmidt constructed a regular Hadamard matrix of order
$4\cdot311^2$ from whole lines and half-lines of the plane $\mathbb F_{311}^2$.
That matrix alone does not reach $3\cdot311$. The product step needs four
disjoint $T$-matrices of order $311^2$ whose row sums are concentrated in one
of them, $(311,0,0,0)$.

The main tool is a completion theorem. Take four functions on the plane
$\mathbb F_q^2$, $q\equiv3\pmod4$. On each line through the origin, each
function is either a sign times the quadratic character or an unspecified
constant. The theorem gives an exact criterion for when the constants can be
chosen so that the four functions give disjoint $T$-matrices with row sums
$(q,0,0,0)$, and an Euler circuit then supplies the constants. Applied to the
half-lines of Leung, Ma and Schmidt at $q=311$, the criterion gives four
disjoint $T$-matrices with row sums $(311,0,0,0)$. A nine-point factor and the
Goethals–Seidel array turn them into the regular matrix of order 3481956.

## What is new

Leung, Ma and Schmidt gave the regular matrix of order $4\cdot311^2$ and the
half-lines used here. Xia, Xia and Seberry showed how concentrated
$T$-matrices multiply, gave them at 7 and 23, and gave the cyclotomic period
equations at $q\equiv7\pmod{16}$. New here:

1. **Principal result: a regular Hadamard matrix of order 3481956**, Menon
   parameter 933 (paper Theorem 1).
2. **The completion theorem** (Theorem 2). Four prescribed arrays of
   quadratic-character signs on the lines of $\mathbb F_q^2$ can be completed
   to four disjoint $T$-matrices with row sums $(q,0,0,0)$ if and only if each
   line carries exactly two character rows, each row leaves an odd number of
   lines constant, and the four character sums have total energy $2q$ at
   every frequency.
3. **Families** (Corollary 4, Theorem 5). The product theorems of Xia, Xia and
   Seberry give regular Hadamard matrices at Menon parameters $311r$ for every
   prime power $r\equiv1\pmod4$, and at $311rm^2$ for every prime
   $r\equiv5\pmod8$ and odd $m$. The parameters with $m\ge3$ number
   asymptotically $\frac{\pi^2/8-1}{1244}\cdot\frac{X}{\log X}$ up to $X$.
4. **An arithmetic criterion** (Theorem 7). The four sign words of the
   certificate work at a prime $p\equiv7\pmod{16}$ exactly when three
   quadratic equations in four integers have a solution with norm $p$. The
   primes 7, 23, 311, 6263 and 63258551 qualify, and there are $O(\log X)$
   such primes up to $X$.

Not new:

- The regular matrix at 311 and its half-lines (Leung, Ma and Schmidt).
- The $T$-matrix product theorems and the concentrated inputs at 7 and 23
  (Xia, Xia and Seberry, 2003).
- The norm and relative-norm equations in Theorem 7, which agree with the
  period equations of Xia, Xia and Seberry (2021).
- The Goethals–Seidel array.

These statements rest on a bounded comparison recorded in
[audit/PRIOR-ART.md](audit/PRIOR-ART.md). We found no earlier construction at
parameter 933 among the sources and product theorems examined. This is not a
claim of global novelty, and no priority is claimed for individual parameters
in the families.

## Earlier work

- **Leung, Ma and Schmidt (2006)**,
  [*New Hadamard matrices of order $4p^2$ obtained from Jacobi sums of order 16*](https://doi.org/10.1016/j.jcta.2005.07.011):
  regular Hadamard matrices of order $4p^2$ from whole lines and half-lines,
  including $p=311$.
- **Xia, Xia and Seberry (2003)**,
  [*Regular Hadamard matrix, maximum excess and SBIBD*](https://ajc.maths.uq.edu.au/pdf/27/ajc_v27_p263.pdf):
  $T$-matrices with concentrated row sums, the product theorems used here, and
  concentrated inputs at 7 and 23.
- **Xia, Xia and Seberry (2007)**,
  [*Some new results of regular Hadamard matrices and SBIBD II*](https://ajc.maths.uq.edu.au/pdf/37/ajc_v37_p117.pdf):
  lists 933 as undetermined.
- **Xia, Xia and Seberry (2021)**,
  [*The construction of regular Hadamard matrices by cyclotomic classes*](https://doi.org/10.1007/s41980-020-00402-9):
  sixteenth-power constructions of order $4q^2$ for $q\equiv7\pmod{16}$; its
  table records no applicable theorem at 311.
- **Crnković (2018)**,
  [*Regular Hadamard matrices constructed from Hadamard 2-designs and conference graphs*](https://doi.org/10.1016/j.disc.2017.09.020):
  lists 933 among 111 unresolved parameters below 1000.

## Evidence and limits

| Claim | Status |
|---|---|
| Theorem 1: regular Hadamard matrix of order 3481956 | proved on paper; certified computation of all summed autocorrelations of the four blocks |
| Theorem 2 (completion) | proved on paper |
| The certificates at 311 (Section 3) | certified computation at every projective frequency, for both certificates |
| Corollary 4 (families) | proved on paper, conditional on the cited theorems of Xia, Xia and Seberry (2003) |
| Theorem 5 (count) | proved on paper |
| Theorem 7 (arithmetic criterion) | proved on paper; the five primes of Table 2 are certified computations |
| Corollary 8 ($O(\log X)$ primes) | proved on paper; the rank of the curve is from PARI/GP and LMFDB |
| Priority at 933 | bounded search; see [audit/PRIOR-ART.md](audit/PRIOR-ART.md) |

Limits:

- The dense matrix of order 3481956 is not stored or built. The check
  computes the summed periodic autocorrelations of the four blocks, which the
  Goethals–Seidel array turns into the Hadamard property.
- Whether infinitely many primes admit concentrated $T$-matrices of this kind
  is open. The four words of Section 3 give $O(\log X)$ of them up to $X$.
- No concentrated $T$-matrices are known at 71, the smallest open prime
  $\equiv7\pmod{16}$.

## Reproduce

The certificates need a C++17 compiler and Ruby; the paper needs pdfLaTeX.

```sh
make verify   # a few seconds on one core
make paper    # builds paper/main.pdf
```

`make verify` writes each output to `build/certificates/` and prints `MATCH`
for each file that equals its pinned copy in `evidence/`.
[VERIFICATION.md](VERIFICATION.md) maps each certificate to the step of the
paper it checks.

## Role of AI

AI assisted the derivations, the computer verification, the literature search
and the exposition under the author's direction. Process-separated AI reviews
checked the proofs and certificates; they are not independent expert peer
review, and no independent human expert has examined the proofs. The audits
and their dispositions are in [audit/LEDGER.md](audit/LEDGER.md).

## License

GPL-3.0-only. See [LICENSE](LICENSE).
