# Admission record

**Current state:** ADMITTED

Current verdict: ADMITTED (2026-11-19)

**Version:** 0.1.0

**Tag:** `v0.1.0` → `066937dbecdbf448db1bf04de4e6973e42e9374b`

**Version DOI:** [`10.5281/zenodo.24377124`](https://doi.org/10.5281/zenodo.24377124) · **Concept DOI:** `10.5281/zenodo.24377123` · **Record:** <https://zenodo.org/records/24377124>

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
| P1 prior work and credit | PARTIAL, residual accepted | `audit/PRIOR-ART.md` and the search log of 2026-11-18/19. Residuals: the body of Xia–Xia–Seberry (2021), and M. Y. Xia (1984) and M. Xia–T. Xia (1999), the closest sources for Theorem 2, were not openly accessible at the time of writing; Crnković (2018) and the manuscript's Remark 3 were read on 2026-11-18 only; one GitHub search was rate limited. A fast-follow rescan on 2026-11-19 at 18:18 UTC, before the tag, found nothing new. On 2026-11-19 the author accepted this residual: "accept lit review as partial, with xia-xia not openly available" |
| A1 claim and artifact consistency | PASS | The author approved the abstract and README introduction (2026-11-19). Cold examiner (Stage 1 NOT-BROKEN, Stage 2 VERIFIED) and three release audits (claims, citations, reproducibility); every finding and its disposition is in `audit/LEDGER.md` |
| R1 release and stewardship | PASS | See below |

## R1 — release and stewardship

| Check | Status | Evidence or residual |
|---|---|---|
| Reproduction | PASS | fresh `git archive` extraction of the draft and of the candidate: `make verify` 3 MATCH, including a must-fail control; deterministic `make paper`, byte-identical to the committed PDF |
| Artifact integrity | PASS | `MANIFEST.sha256` covers every tracked file |
| Hygiene | PASS | README, prior-art and ledger math rendered by GitHub, every span recognized |
| Stewardship | PASS | `CORRECTIONS.md` |
| Immutable semantic tag | PASS | annotated `v0.1.0` (object `8b03a2b`) → `066937d`; tagger is the GitHub noreply identity |
| Public permanent archive with provider byte identity | PASS | the pinned GitHub `zipball/v0.1.0` (downloaded twice, identical) and the Zenodo file are byte-identical: 336567 bytes, SHA-256 `1d3692af44336a3416f5e4182197cf11a975aa22dcdca17ef569260b32f822c6`; Zenodo MD5 `a34310a87a110b1d779649d66997ba47` |
| DOI resolves; living repository identifies the version | PASS | `doi.org/10.5281/zenodo.24377124` redirects to the Zenodo record; README, `CITATION.cff` and the living paper carry the version DOI |
| Archive metadata matches repository | PASS | title, creator Kline, Jeffery, version v0.1.0, publication date 2026-11-19, license `gpl-3.0`, resource type software |
| Machine-readable citation | PASS | `CITATION.cff` with version DOI, concept DOI and `date-released: 2026-11-19` |

**Admission verdict:** ADMITTED (2026-11-19). The P1 residual and the limits
stated in the README remain. No independent human expert has reviewed the
proofs.

## Archive verification

- Route: Zenodo GitHub integration; no manual deposit.
- Pinned before the GitHub Release: GitHub API `zipball/v0.1.0`, downloaded
  twice, identical, 336567 bytes, SHA-256
  `1d3692af44336a3416f5e4182197cf11a975aa22dcdca17ef569260b32f822c6`.
- Zenodo file `jeff-kline/regular-hadamard-933-v0.1.0.zip`: identical to the
  pinned zipball.
- Separate determinism check: `git archive --format=zip v0.1.0`, generated
  twice, identical, 334313 bytes, SHA-256
  `95ed90969207a6f680bd64e0db28871f00d41fe3be89054f2ceb01591ed869d4`; a
  different file from the provider zipball, not compared with it.
- Mechanical audit at the archived state, on the unchanged tagged tree:
  12 pass, 0 warnings, 0 fail.

## External actions and owners

| Action | Owner | Status |
|---|---|---|
| Private GitHub repository and push | author authorization ("make the private repo") | done 2026-11-19 |
| Public visibility, secret scanning and push protection | author authorization ("make it public") | done 2026-11-19 |
| Zenodo enablement before the Release | author, in the Zenodo portal | done 2026-11-19 |
| Annotated tag `v0.1.0`, GitHub Release | author authorization ("proceed") | done 2026-11-19 18:26 UTC: Release "Version 0.1.0" |
| Public-site listing | author authorization | landing entry at <https://jeff-kline.github.io/>; Pages build and live HTML checked for title, blurb, repository link and version DOI before this record was pushed |
| Living-metadata update (this commit) | author authorization | pushed after the site listing was verified live |
