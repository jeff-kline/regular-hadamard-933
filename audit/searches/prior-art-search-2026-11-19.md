# Prior-art and fast-follow search, 2026-11-18/19

Each search is logged with its date and query. A failed or rate-limited
search is recorded as NOT PERFORMED, not as a negative result.

## GitHub (2026-11-19T17:43Z, `gh` CLI, authenticated)

- **Positive control:** `gh search code skew hadamard 1528` returned
  `vatskishan03/Hadamard` files (`skew/1528/README.md` and others). Code
  search was working.
- `gh search code 3481956`: hits in unrelated repositories only (commit
  hashes, numeric tables, a DOI suffix). None concerns Hadamard matrices.
- `gh search code 933 regular hadamard`, `gh search code 933 menon`,
  `gh search code 1866 regular hadamard`: no hits.
- `gh search repos regular hadamard`, `gh search repos menon hadamard`: no
  hits. `gh search repos hadamard matrix`, limit 40: ordinary-order search
  and generation projects, the Hadamard 668 searches, and the author's
  repositories. None mentions regular Hadamard matrices or Menon designs in
  its description.
- Repository-scoped code searches (`regular`, `menon`, `933`):
  - `vatskishan03/Hadamard` (latest commit 2026-11-06): `hadamard/3732`
    gives a skew Hadamard matrix of order $3732=4\cdot933$ from four
    sequences of length 933. It is not regular. The other `regular` hits are
    search scripts and a symmetric matrix of order 8452.
  - `bbeartheancient/hoa64`: `regular` refers only to regular simplices.
  - `georgxzh/hadamard-matrices`: no hits.
  - `sukantaiasri/hadamard-lab`: `regular` no hits; `menon` and `933`
    NOT PERFORMED (rate limited).

## Zenodo (2026-11-19, public records API, sorted by date)

- `"regular Hadamard"`: 2 records, both on complex or prime-order Hadamard
  matrices.
- `"Menon design"`: 1 unrelated record.
- `3481956`: no records.

## arXiv (2026-11-19, export API, sorted by date)

- `all:"regular Hadamard"` (12 results), `ti:"regular Hadamard"` (3) and
  `abs:"regular Hadamard matrices"` (4): none constructs a real regular
  Hadamard matrix at parameter 933 or gives concentrated $T$-matrices at 311.
- `all:Menon AND all:Hadamard` (4 results): includes Momihara–Xiang,
  arXiv:1905.08470, already compared.
- Egan, Kotsireas, London and Ó Catháin, arXiv:2610.27175v2 (updated
  2026-11-03), §4: an ordinary Hadamard matrix of order 3732 from four
  circulants of length 933. It is not regular.

## Forward citations (2026-11-18, OpenAlex API, no key or email)

- Works citing Crnković (2018): 2. Neither gives a regular matrix at 933.
- Works citing Leung–Ma–Schmidt (2006): 18. All titles were screened; the
  closest bodies were read. Incidental results in the others have not all
  been read.

## Sources read in the relevant parts

- Crnković, Discrete Math. 341 (2018): the list of 111 unresolved parameters
  below 1000, which includes 933, and the two conference-graph
  constructions. Read on 2026-11-18; on 2026-11-19 the publisher refused
  access.
- Xia, Xia and Seberry (2003): Definition 7, Theorems 2–4, Proposition 1,
  Lemma 4.
- Xia, Xia and Seberry (2007): the abstract and §4.2 (933 undetermined).
- Xia, Xia and Seberry (2021): the publisher's Appendix A (row 311, no
  applicable theorem). The body was not openly accessible.
- Xia, Seberry and Xia, author manuscript *Constructing regular Hadamard
  matrices by 16th power cyclotomic classes* (University of Wollongong):
  Section 4, Section 9, Appendix A and Remark 3 (311 a gap in the method).
  Read on 2026-11-18; the PDF's text layer is damaged, and on 2026-11-19
  some pages rendered blank.
- Xia, Seberry and Xia, six-page manuscript (University of Wollongong, 2006):
  Theorems 1–3, Corollary 2, Appendix A.
- Leung, Ma and Schmidt (2006): §§3, 5–7 and Appendices 1–3.
- Momihara and Xiang, Finite Fields Appl. 61 (2020): introduction (Turyn's
  product and McFarland's theorem).
- Wallis and Whiteman (1972): Theorem 16 and Corollary 17.
- Seberry and Yamada (1992), §10.2.

## Follow-up (2026-11-19, after the claims audit)

- Web search `Xia Xia "A family of C-partitions and T-matrices" Journal of
  Combinatorial Designs 1999` and `"A new method for constructing T-matrices"
  Xia Seberry Zuo`: bibliographic records only. The 1999 paper (J. Combin.
  Des. 7, 269–281) was not openly accessible. University of Wollongong
  repository pages returned 403.
- Xia, Xia, Seberry and Zuo, *A new method for constructing T-matrices*,
  Australas. J. Combin. 32 (2005), 61–78 (open PDF; text layer damaged, read
  as page images): abstract, introduction and references. It constructs
  $T$-matrices of order $q^2$ for prime powers $q\equiv3\pmod8$ and credits
  $C$-partitions to M. Y. Xia (1984) and their infinite family on
  $GF(q^2)$, $q\equiv3\pmod8$, to M. Xia and T. Xia (1999).

## Pre-tag rescan (2026-11-19T18:18Z)

- GitHub code search: positive control (`skew hadamard 1528`) hit
  `vatskishan03/Hadamard`; `933 regular hadamard`, `3481956 hadamard` and
  `menon 933`: no hits.
- `gh search repos` for `regular hadamard` and `menon`, updated since
  2026-11-18: only this repository and unrelated personal profiles.
- arXiv, newest entries matching "regular Hadamard" or "Menon": none relevant.
