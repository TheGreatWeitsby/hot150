#include<iostream>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1) return strs[0];

    string commonPrefix;
    
    for (int i = 0; i < 200; i++) { // to be modified
        for (int str = 1; str < strs.size(); str++) {
            if (strs[str].size() <= i) return commonPrefix;
            if (strs[str][i] != strs[str - 1][i]) return commonPrefix;
        }
        commonPrefix += strs[0][i];
    }
    return commonPrefix;
}

int main() {
    vector<string> strs = {"dog", "dogg", "dogddd"};
    string commonPrefix = longestCommonPrefix(strs);
    cout << commonPrefix;
}