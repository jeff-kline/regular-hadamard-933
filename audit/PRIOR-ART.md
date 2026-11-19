# Prior art and credit

This is a bounded comparison with the closest known constructions. It is not a
claim of global novelty. The searches are logged in
[searches/prior-art-search-2026-11-19.md](searches/prior-art-search-2026-11-19.md).

## The parameter 933

**Claim:** we found no earlier construction of a regular Hadamard matrix of
order $4\cdot933^2=3481956$ among the sources and product theorems examined.

| Source | What it records | Bearing |
|---|---|---|
| Xia, Xia and Seberry (2007), §4.2 | 933 undetermined | status in 2007 |
| Crnković (2018) | 933 among 111 unresolved parameters below 1000 | status in 2018 |
| Leung, Ma and Schmidt (2006), Appendix 3 | regular matrix of order $4\cdot311^2$ from whole lines and half-lines | supplies the half-lines used here; gives no concentrated $T$-matrices |
| Xia, Xia and Seberry (2021), Appendix A | row 311 with period parameters $(7,-1,7,9)$ and no applicable theorem | the period equations are theirs; their theorems do not reach 311 |
| Xia, Seberry and Xia, manuscript precursor of the 2021 paper, Remark 3 | 311 named as a gap in the sixteenth-power method | as above |
| Egan, Kotsireas, London and Ó Catháin, arXiv:2610.27175v2, §4 | ordinary Hadamard matrix of order 3732 | not regular; no input to a regular product |

Routes checked at 933:

- **Kronecker products** of regular matrices at 3 and 311 give order
  $16\cdot933^2$, not $4\cdot933^2$.
- **Turyn's product of abelian Menon difference sets** needs one of order
  $4\cdot311^2$; McFarland's theorem excludes it (as stated in Momihara and
  Xiang's introduction).
- **Crnković's two conference-graph constructions** need a skew-type design
  whose parameter, 933 or 932, is $3\bmod4$; neither is.
- **Wallis–Whiteman, Corollary 17** at $k=933$ needs a symmetric conference
  matrix of order 1866. We found none in the literature; $1865=5\cdot373$ is
  not a prime power, so the Paley construction does not supply one.
- **The $T$-matrix products of Xia, Xia and Seberry (2003, 2007)** need
  concentrated $T$-matrices at 311. They supply these at 7 and 23, and at
  primes $\equiv3\pmod8$, but not at 311.
- **The 2021 cyclotomic construction** gives four supplementary difference
  sets of equal size at many $q\equiv7\pmod{16}$. Concentrated $T$-matrices
  also need every point to be covered an even number of times, and their
  theorems do not supply this. They record no applicable theorem at 311.

## The completion theorem, families and arithmetic criterion

- **Xia, Xia and Seberry (2003), Theorem 2**: concentrated $T$-matrices from
  supplementary difference sets with even multiplicity. Theorem 2 of the paper
  is a criterion of this kind for the half-line structure, with an explicit
  Euler-circuit completion. We found no source stating this criterion.
- **Families** (Corollary 4, Theorem 5): the existence statements are
  substitutions into Xia, Xia and Seberry (2003), Theorems 3–4, Proposition 1
  and Lemma 4. The count of distinct parameters is new here. No priority is
  claimed for individual parameters in the families.
- **Arithmetic criterion** (Theorem 7): the norm and relative-norm equations
  agree with the period equations of Xia, Xia and Seberry (2021). The third
  equation, which ties them to the four fixed words, and the bound of
  $O(\log X)$ primes are new here.

## Credit

- **Leung, Ma and Schmidt**: the regular matrix at 311 and its half-lines.
- **Xia, Xia and Seberry**: $T$-matrices, their product theorems, the inputs
  at 7 and 23, and the sixteenth-power period equations.
- **Goethals and Seidel**: the array.

## Residuals

- The body of Xia, Xia and Seberry (2021) was not openly accessible at the
  time of writing. Its Appendix A and the manuscript precursor were read.
- Crnković (2018) and the precursor's Remark 3 were read once, in the earlier
  priority pass. A later audit could not open them (publisher refusal and a
  damaged PDF).
- The incidental results of the papers citing Leung–Ma–Schmidt were screened
  by title, not all read.
- Nonabelian Menon difference sets and other product constructions were
  checked only in the cases named above.
- One repository-scoped GitHub search was rate limited (see the search log).
- Unpublished or unindexed constructions cannot be excluded.
