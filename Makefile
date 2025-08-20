# Root Makefile template for 42-style exercises
# - `configure` lists all `exNN` directories (NN = two digits)
# - `all`, `re`, `clean`, `fclean` run the same target in each exNN directory

SHELL := /bin/bash

# Find directories named ex00..ex99 at the top level
EX_DIRS := $(sort $(wildcard ex[0-9][0-9]))

.PHONY: configure all re clean fclean help

define run_target
	@for d in $(EX_DIRS); do \
		if [ -d $$d ]; then \
			echo "----> $$d: $(1)"; \
			$(MAKE) -C $$d $(1) || exit $$?; \
		fi; \
	done
endef

# Generic forwarding rule: if user runs `make <something>`, forward it to each exNN
# Usage: make try  -> runs `make try` inside each `exNN` directory
%:
	$(call run_target,$@)

all:
	$(call run_target,all)

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  configure  - list exNN directories (NN = two digits)"
	@echo "  all        - run 'make all' in each exNN directory"
	@echo "  re         - run 'make re' in each exNN directory"
	@echo "  clean      - run 'make clean' in each exNN directory"
	@echo "  fclean     - run 'make fclean' in each exNN directory"
