#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int evalRPN(vector<string>& tokens) {

    stack<int> st;
    for (string& str: tokens) {
        if (str == "+") {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            st.push(num1 + num2);
        }
        else if (str == "-") {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            st.push(num1 - num2);
        }
        else if (str == "*") {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            st.push(num1 * num2);
        }
        else if (str == "/") {
            int num2 = st.top();
            st.pop();
            int num1 = st.top();
            st.pop();
            st.push(num1 / num2);
        }
        else {
            st.push(stoi(str));
        }
    }

    return st.top();
}

int main() {
    vector<string> tokens = {"2","1","+","3","*"};
    int result = evalRPN(tokens);
    cout << result;
    return 0;
}