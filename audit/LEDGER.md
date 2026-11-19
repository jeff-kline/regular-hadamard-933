# Audit ledger

This file is append-only. Each audit records its scope, what it checked, its
findings and their dispositions. The auditors are process-separated AI agents
in fresh contexts; they are not independent expert reviewers, and their
agreement is not peer review. Finding labels: error, gap, missing hypothesis,
sharpening, documentation.

## 2026-11-18 — reviews of the working notes (before the release cycle)

The working notes behind this paper were reviewed in separate fresh contexts
before the release cycle. The records stay with the working notes and are
summarized here.

- **Completion theorem and the order-933 assembly.**
  - An isolated failure search returned NOT-BROKEN.
  - A proof and certificate audit returned VERIFIED. It used an independent
    recomputation of the 32 table entries, and a deliberately altered mask
    failed as required.
- **Generalized completion.** A strengthening audit gave the converse: under
  the energy condition, every line must carry exactly two character rows.
- **The curve.** A rank-two audit found 6263 and 63258551 and checked both
  directly in the field.
- **Priority passes:**
  - the cited sources;
  - the source bodies of the 2006 manuscript and the 2021 precursor;
  - the forward citations of Crnković and Leung–Ma–Schmidt;
  - other census routes.

## 2026-11-19 — cold examiner on the assembled paper

- **Stage 1** (statements only, sealed SHA-256 e409962a…2d32): NOT-BROKEN for
  all claims.
  - It rebuilt the 311 completion on all of $\mathbb F_{311}^2$ and checked
    the energy with an FFT.
  - It checked the curve, the rank and the five primes in PARI/GP, and
    re-derived the constant in Theorem 5.
  - Finding (documentation): the abstract of Xia–Xia–Seberry (2007) also
    lists individual prime parameters $\equiv7\pmod8$. Disposition: the
    paper's comparison now refers to the infinite families and states that
    the individual parameters are below 1000 and not divisible by 311.
- **Stage 2** (proof audit of the full paper, sealed SHA-256 6f7c60f4…fb32f):
  VERIFIED for the mathematics.
  - It settled the case of a fully prescribed line in Theorem 2, the converse
    in Theorem 7, the reading of Xia–Xia–Seberry Lemma 4, and the
    Leung–Ma–Schmidt appendices.
  - It confirmed that among primes $\equiv7\pmod{16}$ below 1000 only 7, 23
    and 311 satisfy Theorem 7.
  - Crnković (2018), Appendix A of Xia–Xia–Seberry (2021) and the precursor's
    Remark 3 could not be opened in that pass.
  - Eleven errata, all applied:
    - E1 (error, typesetting): `--` in the sign words printed as an en-dash.
    - E2 (error, reasoning): the obstruction for the 2021 construction is
      even multiplicity, not equal sums.
    - E3–E8, E10, E11 (documentation): wording, hypotheses and bibliography.
    - E9 (sharpening): the equal-weight obstruction also covers the
      three-class family.
- **Control added.** `code/check-certificates.rb` now runs a control that
  flips both signs in one column, keeping products and row sums. It fails at
  the energy test, as required.
