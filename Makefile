brainfck: parse_tree brainfck_tests
	./brainfck_tests \
	&& gcc brainfck.c obj/parse_tree.o -o bin/brainfog

brainfck_tests: parse_tree
	gcc tests/tests.c parse_tree.o -o bin/brainfog_tests

parse_tree:
	gcc -c parse_tree.c -o obj/parse_tree.o