#include <stdio.h>
#include <stdlib.h>

#define TREE_MAX_CHILDREN 8


typedef struct tree tree_t;

struct tree {
    tree_t* parent;
    char token;
    int n_children;
    tree_t** children;
};

tree_t* tree_init();
tree_t* tree_add_child(tree_t* parent);
tree_t* tree_parent(tree_t* tree);