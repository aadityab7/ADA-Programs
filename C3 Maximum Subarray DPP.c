#include <stdio.h>

int maxSubArray(int arr[], int size) {
    int maxEndingHere = arr[0];
    int maxSoFar = arr[0];
    
    for (int i = 1; i < size; i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int maxSum = maxSubArray(arr, size);
    
    printf("Maximum sum of subarray: %d\n", maxSum);
    
    return 0;
}
