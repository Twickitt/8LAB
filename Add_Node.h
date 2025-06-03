#include <stdio.h>
#include <stdlib.h>
#include "Structure_one.h"


void Add_Node(Node** polynomy, int coeff, int degree) {
    if (coeff == 0) 
    return;

    Node* new_node = Create_New_Node(coeff, degree);

    if (*polynomy == NULL || (*polynomy)->degree < degree) {
        new_node->next = *polynomy;
        *polynomy = new_node;
        return;
    }

    Node* curr = *polynomy;
    Node* prev = NULL;

    while (curr && curr->degree > degree) { 
        prev = curr;
        curr = curr->next;
    }

    if (curr && curr->degree == degree) {
        free(new_node);  
        return;
    }

    new_node->next = curr;
    
    if (prev) {
        prev->next = new_node;
    } 
    
    else 
        *polynomy = new_node;
    
}