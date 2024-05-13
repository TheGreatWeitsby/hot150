#include<iostream>
#include<vector>

using namespace std;

bool check(int start, int end, string s, vector<string> wordDict) {
    string substr;
    for (int i = start; i <= end; i++) {
        substr += s[i];
    }

    for (string str : wordDict) {
        if (str == substr) return true;
    }
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    // dp[i] 字符串s的前i个字符(0 to i-1)组成的子串能否被wordDict组成
    // dp[i] = dp[j] && check(s[j,j+1,...,i-1]), for j in 0 to i-1
    // dp[0] = true
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= i-1; j++) { // 不带剪枝
            bool isContained = check(j, i-1, s, wordDict);
            if (dp[j] && isContained) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[s.size()];
}

int main() {
    vector<string> wordDict = {"le", "co"};
    string s = "leco";
    bool res = wordBreak(s, wordDict);
    cout << res << endl;
}