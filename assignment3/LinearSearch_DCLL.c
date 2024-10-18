#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL; 

void insert(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL)
     {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    }
     else 
    {
        struct Node* tail = head->prev; 
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

struct Node* search(int key) 
{
    if (head == NULL) return NULL; 

    struct Node* trav = head;
    do {
        if (trav->data == key) {
            return trav;
        }
        trav = trav->next;
    } while (trav != head); 

    return NULL; 
}

int main() 
{
    
    insert(10);
    insert(20);
    insert(30);

    struct Node* result = search(20);
    if (result == NULL) {
        printf("Key not found\n");
    } else {
        printf("Key found!\n");
    }

    return 0;
}
