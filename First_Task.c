#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int degree;
    int coeff;
    struct Node* next;
} Node;


Node* Create_New_Node(int coeff, int degree);


void Add_Node(Node** polynomy, int coeff, int degree);


void Print_Poly(Node* polynomy);

void Free_Poly(Node* polynomy);

Node* Create_Poly(Node* L1, Node* L2);


void Generate_Polynomial(Node** poly, int max_degree);



int main(){

    Node* L1 = NULL;
    Node* L2 = NULL;

    Generate_Polynomial(&L1, 6);
    Generate_Polynomial(&L2, 4);


    printf("Многочлен L1: ");
    Print_Poly(L1);

    printf("Многочлен L2: ");
    Print_Poly(L2);


    Node* L = Create_Poly(L1, L2);

    printf("Многочлен L: ");
    Print_Poly(L);
    

    Free_Poly(L1);
    Free_Poly(L2);


    return 0;
}




Node* Create_New_Node(int coeff, int degree) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node -> coeff = coeff;
    new_node -> degree = degree;
    new_node -> next = NULL;
    return new_node; 
}



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


void Free_Poly(Node* polynomy){
    while(polynomy){

        Node* tmp = polynomy;
        polynomy = polynomy-> next;
        free(tmp);

    }
}


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
