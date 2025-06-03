#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_INPUT 256

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

int UTF8_Strlen(const char* S);

int main() {

    setlocale(LC_ALL, "ru");

    char input[MAX_INPUT];
    Node *head = NULL, *tail = NULL;

    printf("Enter your string(less than 100 simbols, dot at the end of the string):\n");
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

    printf("\nYour string before changes:\n");
    print_list(head);

    int L;
    printf("\nEnter the length of the word to be removed: ");
    scanf("%d", &L);

    delete_by_length(&head, &tail, L);

    printf("\nYour string after changes:\n");
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
        if (UTF8_Strlen(cur->word) == len) {
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

//Данную функцию я позаимствовал у чата, т.к. не понравилось, что strlen() работает с байтами, а такой подход не работает для других языков, например, для русского, из-за кодировки UTF-8(1 символ может занимать больше 1 байта) 
int UTF8_Strlen(const char* S){
    int len = 0;
    while(*S){
        unsigned char c = (unsigned char)*S;
        if((c & 0xC0) != 0x80) 
            len ++;
        S++;
    }

    return len;
}
