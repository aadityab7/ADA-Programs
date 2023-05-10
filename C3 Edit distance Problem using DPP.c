#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int editDistance(char *s, char *t, int m, int n) {
    int dp[m+1][n+1];
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }

    return dp[m][n];
}

int main() {
    char s[] = "sunday";
    char t[] = "saturday";

    int m = strlen(s);
    int n = strlen(t);

    printf("Minimum number of edit operations required: %d\n", editDistance(s, t, m, n));

    return 0;
}
