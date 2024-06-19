brainfog: parse_tree brainfog_tests
	./brainfog_tests \
	&& gcc brainfog.c parse_tree.o -o brainfog

brainfog_tests: parse_tree
	gcc tests/tests.c parse_tree.o -o brainfog_tests

parse_tree:
	gcc -c parse_tree.c -o parse_tree.o