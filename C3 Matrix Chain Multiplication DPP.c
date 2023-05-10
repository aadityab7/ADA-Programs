#include <stdio.h>
#include <limits.h>

#define N 10

int m[N][N], s[N][N];

void matrix_chain_order(int p[], int n) {
    int i, l, j, k, q;
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parens(int s[][N], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int p[N] = {10, 100, 5, 50, 1, 20, 30, 50, 25, 10};
    int n = sizeof(p) / sizeof(p[0]) - 1; // number of matrices
    matrix_chain_order(p, n);
    printf("Minimum number of multiplications: %d\n", m[1][n]);
    printf("Optimal parenthesization: ");
    print_optimal_parens(s, 1, n);
    printf("\n");
    return 0;
}
