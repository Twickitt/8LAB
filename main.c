#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int degree;
    int coeff;
    struct Node* next;
} Node;


Node* Create_New_Node(int coeff, int degree) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node -> coeff = coeff;
    new_node -> degree = degree;
    new_node -> next = NULL;
    return new_node; 
}


//Записываем по порядку члены разных степеней в многочлен 
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

    int max_deg_L2 = -1;
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

    int digits[301] = {0};

    for (int i = max_degree; i >= 0; i--) {
        int coeff; 
        do{

            coeff = rand() % 301 - 150; 

        }while (digits[coeff + 150] || coeff == 0);

        digits[coeff + 150] = 1;

        int deg = rand() % (max_degree + 1);

        Add_Node(poly, coeff, i);
    }
}



int main(){

    Node* L1 = NULL;
    Node* L2 = NULL;

    Generate_Polynomial(&L1, 4);
    Generate_Polynomial(&L2, 3);


    // Пример: L1 = -5x^2 + x^3 + x - 3x^5
    // Add_Node(&L1, 12, 3);
    // Add_Node(&L1, -3, 33);
    // Add_Node(&L1, -1, -6);
    // Add_Node(&L1, -1, -34);

    // Add_Node(&L1, 0, 3);
    // Add_Node(&L1, 0, 33);
    // Add_Node(&L1, 0, -6);
    // Add_Node(&L1, 1, -34);

    // Пример: L2 = 2x^2 - 4x + 7
    // Add_Node(&L2, 2, 2);
    // Add_Node(&L2, -4, 1);
    // Add_Node(&L2, 7, 0);

    printf("Многочлен L1: ");
    Print_Poly(L1);

    printf("Многочлен L2: ");
    Print_Poly(L2);


    Node* L = Create_Poly(L1, L2);

    printf("Многочлен L: ");
    Print_Poly(L);
    

    // Освобождение памяти
    Free_Poly(L1);
    Free_Poly(L2);


    return 0;



}