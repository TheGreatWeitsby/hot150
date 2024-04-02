#include<iostream>

using namespace std;

void removeSpaces(string& s) {
    int slow = 0, fast = 0;

    // delete front spaces
    while (fast < s.size() && s[fast] == ' ')
    {
        fast++;
    }

    // delete middle spaces
    while (fast < s.size()) {
        if (fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ' ') {
            fast++;
        }
        else {
            s[slow] = s[fast];
            slow++;
            fast++;
        }
    }

    // delete back spaces
    if (slow - 1 > 0 && s[slow - 1] == ' ') {
        s.resize(slow - 1);
    }
    else {
        s.resize(slow);
    }
}

void reverse(string& s, int start, int end) {
    // [start, end]
    for (int i = start, j = end; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}

string reverseWords(string s) {
    removeSpaces(s);
    reverse(s, 0, s.size() - 1);
    
    int pre = 0, cur = 0;
    while (cur < s.size()) {
        if (s[cur + 1] == ' ') {
            reverse(s, pre, cur);
            cur += 2;
            pre = cur;
        }
        else if (cur >= s.size() - 1) {
            reverse(s, pre, cur);
            break;
        }
        else {
            cur++;
        }
    }
    return s;
}

int main() {
    string s = "  hello world  ";
    cout << 's' << reverseWords(s) << 'e' << endl;
}