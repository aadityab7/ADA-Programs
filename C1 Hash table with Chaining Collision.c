#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct node* hashTable[], int data) {
    int index = data % TABLE_SIZE;
    struct node* newNode = createNode(data);
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    }
    else {
        struct node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct node* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct node* temp = hashTable[i];
        printf("Index %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct node* hashTable[TABLE_SIZE] = { NULL };
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        insert(hashTable, arr[i]);
    }
    display(hashTable);
    return 0;
}
