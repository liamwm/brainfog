brainfck: parse_tree brainfck_tests
	./brainfck_tests \
	&& gcc brainfck.c parse_tree.o -o brainfck

brainfck_tests: parse_tree
	gcc tests/tests.c parse_tree.o -o brainfck_tests

parse_tree:
	gcc -c parse_tree.c