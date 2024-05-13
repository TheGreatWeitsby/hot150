# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

bool wordPattern(string pattern, string s) {
    vector<string> hashSet(26, "");

    string word;
    vector<string> words;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            words.push_back(word);
            word = "";
        } else
            word += s[i];
    }
    if (word.size())
        words.push_back(word);

    for (int i = 0; i < pattern.size(); i++) {
        if (hashSet[pattern[i] - 'a'] == "") {
            hashSet[pattern[i] - 'a'] = words[i];
        } else {
            if (hashSet[pattern[i] - 'a'] != words[i]) {
                return false;
            }
        }
    }

    return true;
}

bool wordPattern2(string pattern, string s) {
    string word;
    vector<string> words;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            words.push_back(word);
            word = "";
        } else
            word += s[i];
    }
    if (word.size()) words.push_back(word);

    if (words.size() != pattern.size()) return false;

    unordered_map<char, string> pattern2word;
    unordered_map<string, char> word2pattern;

    for (int i = 0; i < pattern.size(); i++) {
        if (pattern2word.count(pattern[i])) {
            if (pattern2word[pattern[i]] == words[i]) continue;
            if (pattern2word[pattern[i]] != words[i]) return false;
        }
        else {
            pattern2word[pattern[i]] = words[i];
        }
    }

    for (int i = 0; i < words.size(); i++) {
        if (word2pattern.count(words[i])) {
            if (word2pattern[words[i]] == pattern[i]) continue;
            if (word2pattern[words[i]] != pattern[i]) return false;
        }
        else {
            word2pattern[words[i]] = pattern[i];
        }
    }

    return true;
}


int main() {
    string pattern = "caba";
    string s = "caba";
    bool res = wordPattern2(pattern, s);
    cout << res << endl;


}