#include<iostream>
#include<vector>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    // dp[i]: 可以凑成金额i所需的最少硬币个数
    // dp[i] = min(dp[i - j] + 1 for j in coins)

    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 0; i <= amount; i++) {
        for (int j = 0; j < coins.size() && i - coins[j] >= 0; i++) {
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {

}