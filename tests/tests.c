#include "tests.h"
#include "../parse_tree.h"


int main(int argc, char* argv[]) {
    parse_tree_test();
    return 0;
}

int parse_tree_test() {
    printf("TEST: Tree init...");
    tree_t* tree = tree_init();
    assert(tree);
    printf("Passed.\n");

    return 1;
}