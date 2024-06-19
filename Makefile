brainfog: parse_tree brainfog_tests
	./bin/brainfog_tests \
	&& gcc brainfog.c obj/parse_tree.o -o bin/brainfog

brainfog_tests: parse_tree
	gcc tests/tests.c obj/parse_tree.o -o bin/brainfog_tests

parse_tree:
	gcc -c parse_tree.c -o obj/parse_tree.o