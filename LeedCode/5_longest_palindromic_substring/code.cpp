#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int expandAroundCenter(string s, int left, int right){
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R]){
            L--;
            R++;
        }
        return R - L - 1;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int max_len = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = max(len1, len2);
            if (len > max_len){
                max_len = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, max_len);
        
    }
};

int main(){
    Solution s;
    cout << s.longestPalindrome("cbbd") << endl;
}