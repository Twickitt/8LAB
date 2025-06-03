#include <stdio.h>
#include <stdlib.h>
#include "Structure_two.h"


void free_list(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp->word);
        free(tmp);
    }
}