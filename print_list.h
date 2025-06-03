#include <stdio.h>
#include <stdlib.h>
#include "Structure_two.h"


void print_list(Node* head) {
    for (Node* cur = head; cur; cur = cur->next) {
        printf("%s ", cur->word);
    }
    printf("\n");
}