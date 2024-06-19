#include "brainfog.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("ERROR: No filename provided.\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("ERROR: File not found.\n");
        return 1;
    }

    char operators[] = "><+-[].,";
    tree_t* syntax_tree = parse(file, operators);

    interpret_statement(syntax_tree);

    return 0;
}

tree_t* parse(FILE* file, char alphabet[]) {
    tree_t* root = tree_init();
    tree_t* tree = root;
    tree->token = '^';

    char c;
    while ((c = fgetc(file)) != EOF) {
        if (!strchr(alphabet, c)) {
            continue;
        }

        tree_t* child = tree_add_child(tree);
        child->token = c;

        if (c == '[') {
            // This child node represents the 'body' of the '[]' operators
            tree_t* body_node = tree_add_child(child);
            body_node->token = '^';
            tree = body_node;
        } else if (c == ']') {
            tree_t* grandparent = tree_parent(tree_parent(tree));
            if (grandparent == NULL) {
                printf("Parse Error: extra ] character.\n");
                exit(1);
            }
            tree = tree->parent->parent;
        }
    }
    
    return root;
}

int interpret_statement(tree_t* statement) {
    tree_t* current = statement;

    char* memory = calloc(256, 1);
    int ptr = 0;

    int result = interpret(statement, memory, &ptr);
    printf("\n");

    free(memory);
    return 0;
}

int interpret(tree_t* statement, char* memory, int* ptr) {
    if (statement == NULL) {
        return 0;
    }

    char token = statement->token;

    switch (token) {
        case '^':
            for (int i=0; i < statement->n_children; i++) {
                int result = interpret(statement->children[i], memory, ptr);
                if (result != 0) {
                    return result;
                }
            }
            break;
        case '>':
            (*ptr)++;
            break;
        case '<':
            (*ptr)--;
            break;
        case '+':
            memory[*ptr]++;
            break;
        case '-':
            memory[*ptr]--;
            break;
        case '[':
            while (memory[*ptr] != 0) {
                interpret(statement->children[0], memory, ptr);
            }
            break;
        case '.':
            printf("%c", memory[*ptr]);
            break;
        case ',':
            scanf("%c", &memory[*ptr]);
            break;
        default:
    }

    return 0;
}

// From left...
// Read character
// Perform operation unless it's a loop character []
// 