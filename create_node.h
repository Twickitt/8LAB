#include <stdio.h>
#include <stdlib.h>
#include "Structure_two.h"


Node* create_node(const char* word) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->word = strdup(word);
    node->prev = node->next = NULL;
    return node;
}