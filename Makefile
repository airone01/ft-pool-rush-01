.PHONY: build

build:
	### build: rush01
	cc -Wall -Wextra -Werror -o rush-01.out *.c

test: test_make_grid clean

clean:
	### clean: tests
	rm -f test_make_grid.out
	### clean: rush
	rm -f rush-01.out

test_make_grid:
	### test: make_grid
	cc -Wall -Wextra -Werror grid.c lib.c tests/make_grid.c -o test_make_grid.out
	./test_make_grid.out
