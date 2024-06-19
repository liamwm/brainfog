#include <stdio.h>
#include <string.h>
#include "parse_tree.h"

#define MEMORY_SIZE 30000;


tree_t* parse(FILE* file, char alphabet[]);
int interpret_statement(tree_t* statement);
int interpret(tree_t* statement, char* memory, int* ptr);