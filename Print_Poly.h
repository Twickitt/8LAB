#include <stdio.h>
#include <stdlib.h>
#include "Structure_one.h"


void Print_Poly(Node* polynomy) {
    if (!polynomy) {
        printf("0\n");
        return;
    }

    Node* curr = polynomy;
    while (curr) {
        
        if (curr->coeff > 0 && curr != polynomy){
            printf("+");
            printf(" ");

        
            if (curr->degree == 0) {
                printf("%d", curr->coeff);
            } 

            else if (curr->coeff == 1) {
                printf("x^%d", curr->degree);
            }

            else if (curr->coeff == -1) {
                printf("- x^%d", curr->degree);
            }
             
            else {
                printf("%d", curr->coeff);
                printf("x^%d", curr->degree);
            }
        }
        else
            if (curr->degree == 0) {
                printf("%d", curr->coeff);
            } 

            else if (curr->coeff == 1) {
                printf("x^%d", curr->degree);
            } 

            else if (curr->coeff == -1) {
                printf("- x^%d", curr->degree);
            } 
            
            else {
                printf("%d", curr->coeff);
                printf("x^%d", curr->degree);
            }

        printf(" ");
        curr = curr->next; 
    }

    printf("\n");
}