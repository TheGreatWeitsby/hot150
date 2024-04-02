#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    if (magazine.size() < ransomNote.size()) return false;
    vector<int> hashSet(26, 0);
    for (char c : magazine) {
        hashSet[c - 'a']++;
    }
    for (char c : ransomNote) {
        hashSet[c - 'a']--;
        if (hashSet[c - 'a'] < 0) return false;
    }
    return true;
}

int main() {
    string ransomNote = "accdd";
    string magazine = "abbcdd";
    cout << canConstruct(ransomNote, magazine) << endl;
}