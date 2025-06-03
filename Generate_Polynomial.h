#include <stdio.h>
#include <stdlib.h>
#include "Structure_one.h"


void Generate_Polynomial(Node** poly, int max_degree) {
    int used[301] = {0};  

    for (int i = max_degree; i >= 0; i--) {
        int coeff;
        do {
            coeff = rand() % 301 - 125; 
        } while (used[coeff + 100]);   

        used[coeff + 100] = 1;         
        Add_Node(poly, coeff, i);
    }
}