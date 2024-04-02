#include<iostream>
#include<unordered_map>

using namespace std;

string intToRoman(int num) {
    // 1000 M
    // 900 CM
    // 500 D
    // 400 CD
    // 100 C
    // 90 XC
    // 50 L
    // 40 XL
    // 10 X
    // 9 IX
    // 5 V
    // 4 IV
    // 1 I

    string s;
    while (num > 0)
    {
        if (num >= 1000) {
            s += 'M';
            num -= 1000;
        }
        else if (num >= 900) {
            s += 'C';
            s += 'M';
            num -= 900;
        }
        else if (num >= 500) {
            s += 'D';
            num -= 500;
        }
        else if (num >= 400) {
            s += 'C';
            s += 'D';
            num -= 400;
        }
        else if (num >= 100) {
            s += 'C';
            num -= 100;
        }
        else if (num >= 90) {
            s += 'X';
            s += 'C';
            num -= 90;
        }
        else if (num >= 50) {
            s += 'L';
            num -= 50;
        }
        else if (num >= 40) {
            s += 'X';
            s += 'L';
            num -= 40;
        }
        else if (num >= 10) {
            s += 'X';
            num -= 10;
        }
        else if (num >= 9) {
            s += 'I';
            s += 'X';
            num -= 9;
        }
        else if (num >= 5) {
            s += 'V';
            num -= 5;
        }
        else if (num >= 4) {
            s += 'I';
            s += 'V';
            num -= 4;
        }
        else if (num >= 1) {
            s += 'I';
            num -= 1;
        }
    }
    
    return s;
}

int main() {
    int num = 1994;
    string s = intToRoman(num);
    cout << s << endl;
}