#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high-1; j++) {
        if (arr[j] > pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

int quick_select(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }
    int pivot = partition(arr, low, high);
    int len = pivot - low + 1;
    if (k == len) {
        return arr[pivot];
    }
    else if (k < len) {
        return quick_select(arr, low, pivot-1, k);
    }
    else {
        return quick_select(arr, pivot+1, high, k-len);
    }
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int result = quick_select(arr, 0, n-1, k);
    printf("%dth largest element is %d\n", k, result);
    return 0;
}
