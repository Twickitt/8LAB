#include <stdio.h>
#include <stdlib.h>
#include "Structure_two.h"


void append(Node** head, Node** tail, const char* word) {
    Node* new_node = create_node(word);

    if (!*head) {

        *head = *tail = new_node;
    } 

    else {

        (*tail)->next = new_node;
        new_node->prev = *tail;
        *tail = new_node;
    }
}