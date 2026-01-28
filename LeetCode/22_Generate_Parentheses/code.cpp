#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> output;

    void goRecursive(int leftP, int rightP, string res, int stack) {
        if ((leftP == 0) && (rightP == 0)) {
            output.push_back(res);
            return;
        }

        if (leftP != 0) {
            goRecursive(leftP - 1, rightP, res + "(", stack + 1);
        }
        if (stack && (rightP != 0)) {
            goRecursive(leftP, rightP - 1, res + ")", stack - 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        goRecursive(n, n, "", 0);
        return output;
    }
};

int main() {
    Solution solution;
    int n = 3;
    vector<string> result = solution.generateParenthesis(n);

    cout << "Generated Parentheses combinations for n = " << n << ":\n";
    for (const auto& combination : result) {
        cout << combination << "\n";
    }

    return 0;
}