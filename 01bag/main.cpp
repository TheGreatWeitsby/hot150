#include<iostream>
#include<vector>

using namespace std;

int bag01(vector<int>& weight, vector<int>& value, int bag) {
    vector<int> dp(bag + 1, 0);
    // dp[i] 背包最大承重为i时，能容纳的最大价值
    // dp[i] = max(dp[i], dp[i - weight[j]] + value[j])
    dp[0] = 0;
    
    for (int i = 0; i < weight.size(); i++) {
        for (int j = bag; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[bag];
}

int bag

int main() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {3, 4, 6};
    int bag = 4;
    int res = bag01(weight, value, bag);
    cout << res << endl;
}