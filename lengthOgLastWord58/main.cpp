#include<iostream>

using namespace std;

int lengthOfLastWord(string s) {
    int right = s.size() - 1;
    int count = 0;

    // 去掉最后的空格
    while (s[right] == ' ')
    {
        right--;
    }

    // 统计长度
    while (right >= 0 && s[right] != ' ')
    {
        count++;
        right--;
    }
    
    return count;
}

int main() {
    string s = "   fly me   to   the moon  ";
    int length = lengthOfLastWord(s);
    cout << length << endl;
}