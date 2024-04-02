#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> umap;
    for (string& str: strs) {
        string key = str;
        sort(key.begin(), key.end());
        umap[key].push_back(str);
    }

    vector<vector<string>> result;
    for (auto it = umap.begin(); it != umap.end(); it++) {
        result.push_back(it->second);
    }

    return result;
}

int main() {
    vector<string> strs = {"eat", "ate", "ttae"};
    vector<vector<string>> result = groupAnagrams(strs);
    for (auto strings: result) {
        for (string s: strings) {
            cout << s << ' ';
        }
        cout << endl;
    }
}