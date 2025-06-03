#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 101

typedef struct Node {
    char* word;
    struct Node* prev;
    struct Node* next;
} Node;

Node* create_node(const char* word);

void append(Node** head, Node** tail, const char* word);

void print_list(Node* head);

void delete_by_length(Node** head, Node** tail, int len);

void free_list(Node* head);

int main() {

    char input[MAX_INPUT];
    Node *head = NULL, *tail = NULL;

    printf("Введите строку (не более 100 символов, в конце точка):\n");
    fgets(input, MAX_INPUT, stdin);

    input[strcspn(input, "\n")] = '\0'; 

   
    int len = strlen(input);

    if (input[len -1] == '.') 
        input[len -1] = '\0';

 
    char* word = strtok(input, " ");
    while (word) {
        append(&head, &tail, word);
        word = strtok(NULL, " ");
    }

    printf("\nСписок до удаления:\n");
    print_list(head);

    int L;
    printf("\nВведите длину слов для удаления: ");
    scanf("%d", &L);

    delete_by_length(&head, &tail, L);

    printf("\nСписок после удаления:\n");
    print_list(head);

    free_list(head);
    return 0;
}






Node* create_node(const char* word) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->word = strdup(word);
    node->prev = node->next = NULL;
    return node;
}


void append(Node** head, Node** tail, const char* word) {
    Node* new_node = create_node(word);

    if (!*head) {

        *head = *tail = new_node;
    } 

    else {

        (*tail)->next = new_node;
        new_node->prev = *tail;
        *tail = new_node;
    }
}


void print_list(Node* head) {
    for (Node* cur = head; cur; cur = cur->next) {
        printf("%s ", cur->word);
    }
    printf("\n");
}


void delete_by_length(Node** head, Node** tail, int len) {
    Node* cur = *head;
    while (cur) {
        Node* next = cur->next;
        if (strlen(cur->word) == len) {
            if (cur->prev) 
                cur->prev->next = cur->next;
            else 
                *head = cur->next;

            if (cur->next) 
                cur->next->prev = cur->prev;
            else 
                *tail = cur->prev;

            free(cur->word);
            free(cur);
        }
        cur = next;
    }
}


void free_list(Node* head) {
    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp->word);
        free(tmp);
    }
}