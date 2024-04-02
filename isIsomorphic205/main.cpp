#include<iostream>
#include<unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> s2t;
    unordered_map<char, char> t2s;

    int len = s.length();
    for (int i = 0; i < len; i++) {
        char sChar = s[i];
        char tChar = t[i];
        if (s2t.count(sChar) && s2t[sChar] != tChar) return false;
        if (t2s.count(tChar) && t2s[tChar] != sChar) return false;
        s2t[sChar] = tChar;
        t2s[tChar] = sChar;
    }

    return true;
}

int main() {
    string s = "egg";
    string t = "add";
    cout << isIsomorphic(s, t);
    
}