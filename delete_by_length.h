#include <stdio.h>
#include <stdlib.h>
#include "Structure_two.h"


void delete_by_length(Node** head, Node** tail, int len) {
    Node* cur = *head;
    while (cur) {
        Node* next = cur->next;
        if (strlen(cur->word) == len) {
            if (cur->prev) 
                cur->prev->next = cur->next;
            else 
                *head = cur->next;

            if (cur->next) 
                cur->next->prev = cur->prev;
            else 
                *tail = cur->prev;

            free(cur->word);
            free(cur);
        }
        cur = next;
    }
}