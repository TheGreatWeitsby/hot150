#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if (umap.count(num) && i - umap[num] <= k) return true;
        else {
            umap[num] = i;
        }
    }
    return false;
}