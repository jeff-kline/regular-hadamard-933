# Admission record

**Current state:** DRAFT

Current verdict: NOT YET ADMITTED

**Version:** 0.1.0 (in preparation)

**Standard:** [A Public Standard for This Work](https://jeff-kline.github.io/posts/research-program/index.html)

Admission is a project release decision. It is not peer review, a correctness
certificate, or proof of global novelty.

**Scope set by the author.** The author made three decisions:

- On 2026-11-19 they asked for the paper to be drafted ("draft the 933
  paper").
- They agreed to a standalone release named `regular-hadamard-933`, with the
  cold examiner first.
- They approved the abstract and README introduction ("approved").

## Principal claim

There is a regular Hadamard matrix of order $4\cdot933^2=3481956$ with common
row and column sum 1866 (paper Theorem 1). We found no earlier construction at
parameter 933 among the sources and product theorems examined.

Further results:

- the completion theorem (Theorem 2);
- families of regular parameters $311r$ and $311rm^2$, with a count
  (Corollary 4, Theorem 5);
- an arithmetic criterion for one fixed set of four words, with $O(\log X)$
  admissible primes (Theorem 7, Corollary 8).

Limits: no priority is claimed for individual parameters in the families;
concentrated $T$-matrices at 71 are not known.

## Gates

| Gate | Status | Evidence or residual |
|---|---|---|
| P1 prior work and credit | PARTIAL | `audit/PRIOR-ART.md` and the search log of 2026-11-18/19. Residuals: the body of Xia–Xia–Seberry (2021) was not openly accessible at the time of writing; Crnković (2018) and the manuscript's Remark 3 were read once; one GitHub search was rate limited |
| A1 claim and artifact consistency | IN PROGRESS | Cold examiner: Stage 1 NOT-BROKEN, Stage 2 VERIFIED, 11 errata applied. Release audits pending |
| R1 release and stewardship | IN PROGRESS | `make verify` (3 MATCH) and `make paper` pass. No tag, archive or DOI yet |
