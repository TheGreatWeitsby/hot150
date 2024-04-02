#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int right;
    int sum = 0;
    int len = 0;
    int minLen = INT_MAX;

    for (right = 0; right < nums.size(); right++) {
        len++;
        sum += nums[right];
        if (sum >= target) {
            minLen = min(minLen, len);
            while(left <= right && sum >= target) {
                minLen = min(minLen, len);
                sum -= nums[left];
                left++;
                len--;
            }
        }
        else {
            continue;
        }
    }

    return minLen == INT_MAX ? 0 : minLen;
}

int main() {
    vector<int> nums = {1,1,1,1,1,1,1,1};
    int minLen = minSubArrayLen(11,  nums);
    cout << minLen << endl;
}