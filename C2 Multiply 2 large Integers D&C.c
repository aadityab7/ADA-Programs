#include <stdio.h>
#include <string.h>

void reverse(char str[], int length) {
    int i, j;
    for (i = 0, j = length-1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void multiply(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == 0 || len2 == 0) {
        result[0] = '0';
        result[1] = '\0';
        return;
    }
    int res[len1+len2];
    for (int i = 0; i < len1+len2; i++) {
        res[i] = 0;
    }
    int i1 = 0, i2 = 0;
    for (int i = len1-1; i >= 0; i--) {
        int carry = 0;
        int n1 = num1[i] - '0';
        i2 = 0;
        for (int j = len2-1; j >= 0; j--) {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + res[i1 + i2] + carry;
            carry = sum / 10;
            res[i1 + i2] = sum % 10;
            i2++;
        }
        if (carry > 0) {
            res[i1 + i2] += carry;
        }
        i1++;
    }
    int j = len1 + len2 - 1;
    while (j >= 0 && res[j] == 0) {
        j--;
    }
    if (j == -1) {
        result
