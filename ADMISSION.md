# Admission record

**Current state:** CANDIDATE

Current verdict: NOT YET ADMITTED

**Version:** 0.1.0 (release candidate)

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
we know no group-developed concentrated $T$-matrices of order $71^2$.

## Gates

| Gate | Status | Evidence or residual |
|---|---|---|
| P1 prior work and credit | PARTIAL | `audit/PRIOR-ART.md` and the search log of 2026-11-18/19. Residuals: the body of Xia–Xia–Seberry (2021), and M. Y. Xia (1984) and M. Xia–T. Xia (1999), the closest sources for Theorem 2, were not openly accessible at the time of writing; Crnković (2018) and the manuscript's Remark 3 were read on 2026-11-18 only; one GitHub search was rate limited |
| A1 claim and artifact consistency | PASS | The author approved the abstract and README introduction (2026-11-19). Cold examiner (Stage 1 NOT-BROKEN, Stage 2 VERIFIED) and three release audits (claims, citations, reproducibility); every finding and its disposition is in `audit/LEDGER.md` |
| R1 release and stewardship | IN PROGRESS | `make verify` (3 MATCH, with a must-fail control) and a deterministic `make paper` pass, also from a clean `git archive`; correction policy, CITATION.cff and MANIFEST.sha256 present. No tag, archive or DOI yet |
