#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> keypad = {{},
                                       {},
                                       {'a', 'b', 'c'},
                                       {'d', 'e', 'f'},
                                       {'g', 'h', 'i'},
                                       {'j', 'k', 'l'},
                                       {'m', 'n', 'o'},
                                       {'p', 'q', 'r', 's'},
                                       {'t', 'u', 'v'},
                                       {'w', 'x', 'y', 'z'}};
        vector<string> result;

        if (digits.empty()) {
            return result;
        }

        // Inline recursive function
        function<void(int, string)> backtrack = [&](int index, string current) {
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }

            int digit = digits[index] - '0';
            for (char c : keypad[digit]) {
                backtrack(index + 1, current + c);
            }
        };

        backtrack(0, "");  // Start recursion
        return result;
    }
};

int main() {
    Solution s;
    vector<string> out;
    out = s.letterCombinations("23");

    for (string s : out) {
        cout << s << ", ";
    }
    cout << endl;
}