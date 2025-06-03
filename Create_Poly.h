#include <stdio.h>
#include <stdlib.h>
#include "Structure_one.h"


Node* Create_Poly(Node* L1, Node* L2){

    int max_deg_L2; 
    Node* curr = L2;
    while(curr){
        if(curr -> degree > max_deg_L2)
            max_deg_L2 = curr->degree;
        
        curr = curr->next;

    }

    Node* new_poly = NULL;
    curr = L1;
    while(curr){
        if (curr->degree > max_deg_L2)
            Add_Node(&new_poly, curr->coeff, curr->degree);
        curr = curr->next;

    }
    
    return new_poly;
}