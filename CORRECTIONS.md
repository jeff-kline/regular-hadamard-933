# Corrections, withdrawals, and supersession

This repository keeps a visible record of material corrections to released
claims and artifacts.

## Policy

- Minor typographical or navigational fixes may be made on the living default
  branch without changing an archived release.
- A change to a theorem statement, hypothesis, proof dependency, citation that
  affects priority or scope, or verification artifact creates a new version.
  The earlier tag and permanent archive remain unchanged and identifiable.
- A material error that invalidates a principal claim will be marked
  prominently in the README and in this file. The affected release will not be
  deleted or silently replaced.
- A withdrawn result remains findable with the reason, date, affected
  versions, and any replacement or correction linked here.
- Public tags and archived files are immutable. Corrections are made in a new
  commit and, when material, a new tagged release.
- If an earlier construction of a regular Hadamard matrix of order
  $4\cdot933^2$, or of concentrated $T$-matrices at 311, is found, the
  corresponding priority statement will be withdrawn and the source credited
  in a new version. The sources not openly accessible at the time of writing
  are listed in [audit/PRIOR-ART.md](audit/PRIOR-ART.md).

Suspected errors may be reported through the repository's issue tracker:
<https://github.com/jeff-kline/regular-hadamard-933/issues>.

## Version history

### 0.1.0 — released 2026-11-19

- Tag `v0.1.0` at commit `066937d`; version DOI
  [`10.5281/zenodo.24377124`](https://doi.org/10.5281/zenodo.24377124), concept DOI `10.5281/zenodo.24377123`.
- The tagged snapshot retains its prepublication “release candidate” wording
  and carries no DOI, because the DOI was minted by Zenodo after the GitHub
  Release. The living repository and paper now carry the active DOI; the
  archived files were not changed.
- Release preparation, before the tag: the dispositions of all audit findings
  are in [audit/LEDGER.md](audit/LEDGER.md).
