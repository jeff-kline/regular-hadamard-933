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

## 2026-11-19 — release audits of draft commit c0c4e7e

Three read-only audits in fresh contexts.

- **Reproducibility.** PASS.
  - A clean `git archive` gives 3 MATCH; `make paper` is deterministic and
    byte-identical to the committed PDF.
  - Findings and dispositions:
    - math in README link text was not rendered (documentation): fixed;
    - the negative control accepted any failure (documentation): it now
      requires the energy failure;
    - MANIFEST.sha256 was missing (documentation): added at the candidate.
- **Citations.** One error: the third author of Egan et al. is S. London
  (fixed).
  - Sources not openly accessible are listed as residuals in
    `audit/PRIOR-ART.md`.
  - Leung–Ma–Schmidt is paywalled at the publisher; its appendices were read
    from the author-hosted copy in the proof audit.
  - The Momihara–Xiang entry now uses its DOI.
- **Claims and assembled manuscript.** PASS-WITH-FIXES. All numbers, the
  numbering, the 11 cold-examiner errata and the Stage 1 and Stage 2 hashes
  check out.
  - Findings:
    1. (gap) Xia–Xia–Seberry (2003), Proposition 4, gives concentrated
       $T$-matrices at every prime power $q\equiv3\pmod8$, citing M. Xia and
       T. Xia (1999).
    2. (gap) The closest prior art for Theorem 2, $C$-partitions (M. Y. Xia
       1984; M. Xia and T. Xia 1999), was neither cited nor read.
    3. (error) "every frequency" should be "every nonzero frequency".
    4. (missing hypothesis) The README's statement of Theorem 2 lacked
       $q\equiv3\pmod4$.
    5. (sharpening) The converse for the $T$-matrices was not stated.
    6. (sharpening) The README's statement of Theorem 7 counted the norm
       twice.
    7–8. (documentation) The 71 and "infinitely many" limits overstated the
       paper.
    9–10. (documentation) There was unhedged novelty and an unhedged
       "not known".
    11. (documentation) The nine-point product was not credited to
        Xia–Xia–Seberry Theorem 4.
    12. (documentation) The README did not say which certificate the full
        check uses.
    13. (documentation) The sign convention of the 2021 table was not stated.
    14. (documentation) There was process wording in the prior-art files.
    15. (documentation) The MANIFEST link was dead.
    16. (documentation) The version line differed from the README status.
    17. (documentation) README link-text math was not rendered.
    18. (documentation) The PDF text layer has "Crnkovi¢".
    19–20. (documentation) The completion-rule indexing and the MX link.
    21. (gap, residual) Some claims rest on sources not re-read.
  - Dispositions:
    - Items 1, 2 and 9: the paper and README now credit $C$-partitions and
      their construction at $q\equiv3\pmod8$. The novelty of Theorem 2 is
      hedged to the sources read, and both papers are recorded as not openly
      accessible. A follow-up search is logged.
    - Items 3–8, 10–15, 17, 19–21: fixed as proposed.
    - Item 16: the version line and README status are aligned at the
      candidate commit.
    - Item 18: not fixed. `\pdfgentounicode` fixes the ligatures, but the T1
      glyph for "ć" in the default fonts still extracts as "¢". Adding
      `lmodern` is excluded by the release convention. Cosmetic.
