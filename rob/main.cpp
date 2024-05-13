#include<iostream>
#include<vector>

using namespace std;

int rob(vector<int>& nums) {
    // 动态数组定义 dp[i]表示0-i家能偷到的最大金额
    // dp[i] = max(dp[i-1], dp[i-2] + nums[i])
    // 初始化 dp[0] = nums[0], dp[1] = max(nums[0], nums[1])

    if (nums.size() == 1) return nums[0];

    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
        dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[nums.size() - 1];
}

int main() {
    vector<int> nums = {1,2,3,1};
    int maxMoney = rob(nums);
    cout << maxMoney << endl;
}