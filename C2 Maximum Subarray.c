#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max_crossing_sum(int arr[], int low, int mid, int high) {
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }
    sum = 0;
    for (int i = mid+1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }
    return max(max(left_sum, right_sum), left_sum + right_sum);
}

int max_subarray_sum(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = (low + high) / 2;
    int left_sum = max_subarray_sum(arr, low, mid);
    int right_sum = max_subarray_sum(arr, mid+1, high);
    int crossing_sum = max_crossing_sum(arr, low, mid, high);
    return max(max(left_sum, right_sum), crossing_sum);
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = max_subarray_sum(arr, 0, n-1);
    printf("Maximum Subarray Sum is %d\n", result);
    return 0;
}
