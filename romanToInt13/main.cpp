#include<iostream>
#include<unordered_map>

using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> umap;
    umap['I'] = 1;
    umap['V'] = 5;
    umap['X'] = 10;
    umap['L'] = 50;
    umap['C'] = 100;
    umap['D'] = 500;
    umap['M'] = 1000;

    if (s.size() == 1) return umap[s[0]];

    int left = 0, right = 1;
    int sum = 0;

    while (left < s.size())
    {
        if (right < s.size()) {
            if (umap[s[left]] < umap[s[right]]) {
                if (s[left] == 'I' && s[right] == 'V') {
                    sum += umap['V'] - umap['I'];
                }
                else if (s[left] == 'I' && s[right] == 'X') {
                    sum += umap['X'] - umap['I'];
                }
                else if (s[left] == 'X' && s[right] == 'L') {
                    sum += umap['L'] - umap['X'];
                }
                else if (s[left] == 'X' && s[right] == 'C') {
                    sum += umap['C'] - umap['X'];
                }
                else if (s[left] == 'C' && s[right] == 'D') {
                    sum += umap['D'] - umap['C'];
                }
                else if (s[left] == 'C' && s[right] == 'M') {
                    sum += umap['M'] - umap['C'];
                }
                left += 2;
                right += 2;
            }
            else {
                sum += umap[s[left]];
                left++;
                right++;
            }
        }
        else {
            sum += umap[s[left]];
            left++;
        }
    }
    
    return sum;
}

int main() {
    string s = "IX";
    int result = romanToInt(s);
    cout << result << endl;
}