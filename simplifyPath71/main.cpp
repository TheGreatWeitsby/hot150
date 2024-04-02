#include <iostream>
#include <stack>

using namespace std;

string simplifyPath(string path) {
    string folder;
    stack<string> st;
    bool prev = false;

    for (char ch : path) {
        if (ch == '/') {
            if (prev == true) {
                continue;
            }
            else {
                st.push(folder);
                folder = "";
                prev = true;
            }
        }
        else {
            folder += ch;
            prev = false;
        }
    }
    if (folder.size() > 0) st.push(folder);

    int back = 0;
    string result;
    while (!st.empty())
    {
        string str = st.top();
        st.pop();

        if (str != "." && str != "..") {
            if (back > 0)
            {
                back--;
                continue;
            }
            result = str + '/' + result;
        }
        else if (str == ".") continue;
        else if (str == "..") {
            back++;
        }
    }
    

    if (result[0] != '/') result =  "/" + result;
    if (result.size() > 1 && result[result.size() - 1] == '/') result.pop_back();

    return result;
}

int main() {
    string path = "/a/../../b/../c//.//";
    string result = simplifyPath(path);
    cout << result << endl;
}