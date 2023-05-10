#include <stdio.h>
#include <stdlib.h>

int longestIncreasingSubsequence(int arr[], int n) {
    int lis[n], maxLis = 0;
    for (int i = 0; i < n; i++) {
        lis[i] = 1; // initialize each element as a subsequence of length 1
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[j] + 1 > lis[i]) {
                lis[i] = lis[j] + 1; // update length of subsequence
            }
        }
        if (lis[i] > maxLis) {
            maxLis = lis[i]; // update max length of subsequence
        }
    }
    return maxLis;
}

int main() {
    int arr[] = {3, 4, -1, 0, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Longest increasing subsequence length: %d\n", longestIncreasingSubsequence(arr, n));
    return 0;
}
