#include <stdio.h>
#include <stdlib.h>
#include "Structure_one.h"


void Free_Poly(Node* polynomy){
    while(polynomy){

        Node* tmp = polynomy;
        polynomy = polynomy-> next;
        free(tmp);

    }
}