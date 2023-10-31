#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int max = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) != map.end()) {
                if (map[s[i]] >= start) {
                    start = map[s[i]] + 1;
                }
            }
            map[s[i]] = i;
            if (i - start + 1 > max) {
                max = i - start + 1;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout << s.lengthOfLongestSubstring("") << endl;
    cout << s.lengthOfLongestSubstring(" ") << endl;
    cout << s.lengthOfLongestSubstring("au") << endl;
    cout << s.lengthOfLongestSubstring("dvdf") << endl;
    cout << s.lengthOfLongestSubstring("abba") << endl;
    return 0;
}