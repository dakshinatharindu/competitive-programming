#include <iostream>

using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        char prev;
        int i = 0, j = 0;
        while (j <= s.size()) {
            if (i == p.size()) {
                return false;
            }

            if (p[i] == s[j] || p[i] == '.') {
                prev = s[j];
                i++;
                continue;
            }

            if (p[i] == '*') {
                if (prev == s[j]) {
                    j++;
                    continue;
                } else {
                    i++;
                    continue;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << s.isMatch("aa", "a*") << endl;
}
