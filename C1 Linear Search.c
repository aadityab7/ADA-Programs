#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 22;
    int index = linearSearch(arr, n, x);
    if (index == -1) {
        printf("Element %d not found in array\n", x);
    }
    else {
        printf("Element %d found at index %d\n", x, index);
    }
    return 0;
}
