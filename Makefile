.PHONY: build

build:
	@echo "### Compilation avec cc..."
	cc -Wall -Wextra -Werror -o rush-01 *.c

test_make_grid:
	@echo "### Compilation et test de make_grid..."
	cc -Wall -Wextra -Werror grid.c lib.c tests/make_grid.c
	./a.out|cat -e
