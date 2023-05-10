#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        int left = factorial(n/2);
        int right = factorial(n/2);
        if (n % 2 == 0) {
            return left * right;
        }
        else {
            return left * right * n;
        }
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    int result = factorial(n);
    printf("Factorial of %d is %d\n", n, result);
    return 0;
}
