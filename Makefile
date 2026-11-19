SHELL := /bin/sh
CXX ?= c++
RUBY ?= ruby
PDFLATEX ?= pdflatex
export SOURCE_DATE_EPOCH := 1795046400
export FORCE_SOURCE_DATE := 1

.PHONY: paper verify

# Three passes from a clean extraction; no inherited auxiliaries are required.
paper:
	cd paper && $(PDFLATEX) -interaction=nonstopmode -halt-on-error main.tex >/dev/null
	cd paper && $(PDFLATEX) -interaction=nonstopmode -halt-on-error main.tex >/dev/null
	cd paper && $(PDFLATEX) -interaction=nonstopmode -halt-on-error main.tex >/dev/null
	@! grep -E 'Warning:|Overfull|undefined references|undefined citations' paper/main.log
	@echo "paper built: paper/main.pdf"

# Run every certificate (a few seconds on one core) and compare each output
# with the pinned copy in evidence/.
verify:
	@rm -rf build/certificates
	@CXX="$(CXX)" RUBY="$(RUBY)" sh code/run-certificates.sh build/certificates
	@for f in evidence/*.txt; do \
	  if cmp -s "$$f" "build/certificates/$${f#evidence/}"; then echo "MATCH $${f#evidence/}"; \
	  else echo "MISMATCH $${f#evidence/}"; exit 1; fi; done
	@test "$$(ls evidence/*.txt | wc -l)" -eq "$$(ls build/certificates/*.txt | wc -l)"
	@echo "verify: all certificate outputs match evidence/"
