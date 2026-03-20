#include <stdio.h>

int main() {
    int n;

    // Input size
    scanf("%d", &n);

    int prices[100];

    // Input prices
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    int min_price = prices[0];
    int max_profit = 0;

    for (int i = 1; i < n; i++) {
        // Update minimum price
        if (prices[i] < min_price) {
            min_price = prices[i];
        }

        // Calculate profit
        int profit = prices[i] - min_price;

        // Update max profit
        if (profit > max_profit) {
            max_profit = profit;
        }
    }

    printf("%d", max_profit);

    return 0;
}