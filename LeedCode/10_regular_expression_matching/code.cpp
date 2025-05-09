#include <iostream>

using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();

        bool dp[m + 1][n + 1];
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;

        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*' && dp[0][j - 2]) dp[0][j] = true;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2]; 
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution s;
    cout << s.isMatch("mississippi", "mis*is*p*.") << endl;
}
