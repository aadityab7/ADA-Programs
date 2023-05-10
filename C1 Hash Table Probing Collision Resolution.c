#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

struct node {
    int key;
    int value;
};

struct node* createNode(int key, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->value = value;
    return newNode;
}

void insert(struct node* hashTable[], int key, int value) {
    int index = hashFunction(key);
    if (hashTable[index] == NULL) {
        hashTable[index] = createNode(key, value);
    }
    else {
        int i = 1;
        int newIndex = (index + i) % TABLE_SIZE;
        while (hashTable[newIndex] != NULL && newIndex != index) {
            i++;
            newIndex = (index + i) % TABLE_SIZE;
        }
        if (hashTable[newIndex] == NULL) {
            hashTable[newIndex] = createNode(key, value);
        }
        else {
            printf("HashTable is full\n");
        }
    }
}

void display(struct node* hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("Index %d: Key=%d, Value=%d\n", i, hashTable[i]->key, hashTable[i]->value);
        }
        else {
            printf("Index %d: NULL\n", i);
        }
    }
}

int search(struct node* hashTable[], int key) {
    int index = hashFunction(key);
    if (hashTable[index] != NULL && hashTable[index]->key == key) {
        return hashTable[index]->value;
    }
    else {
        int i = 1;
        int newIndex = (index + i) % TABLE_SIZE;
        while (hashTable[newIndex] != NULL && newIndex != index) {
            if (hashTable[newIndex]->key == key) {
                return hashTable[newIndex]->value;
            }
            i++;
            newIndex = (index + i) % TABLE_SIZE;
        }
        return -1;
    }
}

int main() {
    struct node* hashTable[TABLE_SIZE] = { NULL };
    insert(hashTable, 10, 100);
    insert(hashTable, 20, 200);
    insert(hashTable, 25, 250);
    insert(hashTable, 35, 350);
    insert(hashTable, 45, 450);
    insert(hashTable, 55, 550);
    display(hashTable);
    int key = 20;
    int value = search(hashTable, key);
    if (value == -1) {
        printf("Key %d not found in hash table\n", key);
    }
    else {
        printf("Value for key %d is %d\n", key, value);
    }
    return 0;
}
