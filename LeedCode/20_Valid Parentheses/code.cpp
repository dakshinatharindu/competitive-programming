#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') || (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution solution;
    string s = "()[]{}";
    cout << (solution.isValid(s) ? "true" : "false") << endl;  // Output: true

    s = "(]";
    cout << (solution.isValid(s) ? "true" : "false") << endl;  // Output: false

    s = "([)]";
    cout << (solution.isValid(s) ? "true" : "false") << endl;  // Output: false

    s = "{[]}";
    cout << (solution.isValid(s) ? "true" : "false") << endl;  // Output: true

    return 0;
}