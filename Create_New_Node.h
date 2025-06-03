#include<stdio.h>
#include<stdlib.h>
#include "Structure_one.h"


Node* Create_New_Node(int coeff, int degree) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node -> coeff = coeff;
    new_node -> degree = degree;
    new_node -> next = NULL;
    return new_node; 
}