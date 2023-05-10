#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int* data;
    int size;
    int capacity;
} Heap;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->data = (int*)malloc(sizeof(int) * (capacity + 1));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void insert(Heap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow!\n");
        return;
    }
    heap->size++;
    heap->data[heap->size] = value;
    int i = heap->size;
    while (i > 1 && heap->data[i / 2] < heap->data[i]) {
        swap(&heap->data[i / 2], &heap->data[i]);
        i /= 2;
    }
}

int deleteMax(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap underflow!\n");
        return -1;
    }
    int max = heap->data[1];
    heap->data[1] = heap->data[heap->size];
    heap->size--;
    int i = 1;
    while (i * 2 <= heap->size) {
        int j = i * 2;
        if (j + 1 <= heap->size && heap->data[j + 1] > heap->data[j]) {
            j++;
        }
        if (heap->data[i] >= heap->data[j]) {
            break;
        }
        swap(&heap->data[i], &heap->data[j]);
        i = j;
    }
    return max;
}

void heapSort(int* arr, int n) {
    Heap* heap = createHeap(n);
    for (int i = 0; i < n; i++) {
        insert(heap, arr[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = deleteMax(heap);
    }
    free(heap->data);
    free(heap);
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3, 8, 6, 4};
    int n = sizeof(arr) / sizeof(int);
    printf("Before sorting: ");
    printArray(arr, n);
    heapSort(arr, n);
    printf("After sorting: ");
    printArray(arr, n);
    return 0;
}
