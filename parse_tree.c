#include "parse_tree.h"


/*
TODO:
[*] init tree
[*] add child
[] delete child
[] delete tree
*/

tree_t* tree_init() {
    tree_t* tree = malloc(sizeof(tree_t));
    if (tree == NULL) {
        printf("ERROR: tree memory allocation failed.\n");
        return NULL;
    }

    tree->parent = NULL;
    tree->token = ' ';
    tree->n_children = 0;
    tree->children = NULL;

    return tree;
}

tree_t* tree_add_child(tree_t* parent) {
    tree_t* child = tree_init();
    child->parent = parent;

    if (parent->children == NULL) {
        tree_t** children = malloc(TREE_MAX_CHILDREN * sizeof(tree_t*));
        if (children == NULL) {
            printf("ERROR: Failed to allocate memory for tree children addresses.\n");
        }
        parent->children = children;

    }

    parent->children[parent->n_children++] = child;

    return child;
}

tree_t* tree_parent(tree_t* tree) {
    if (tree == NULL) {
        return NULL;
    }
    return tree->parent;
}