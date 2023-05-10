#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int coinChange(int coins[], int numCoins, int amount) {
    int i, j, dp[amount+1];
    dp[0] = 0;

    for(i=1; i<=amount; i++) {
        dp[i] = INT_MAX;
        for(j=0; j<numCoins; j++) {
            if(coins[j] <= i) {
                int subRes = dp[i - coins[j]];
                if(subRes != INT_MAX && subRes + 1 < dp[i]) {
                    dp[i] = subRes + 1;
                }
            }
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int numCoins = sizeof(coins) / sizeof(coins[0]);
    int amount = 63;

    int res = coinChange(coins, numCoins, amount);
    printf("Minimum number of coins required to make %d cents: %d\n", amount, res);

    return 0;
}
