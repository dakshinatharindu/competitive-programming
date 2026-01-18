#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
        vector<pair<char, int>> stack;
        vector<pair<int, int>> intervals;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push_back({s[i], i});
            } else {
                if (!stack.empty() && stack.back().first == '(') {
                    int start = stack.back().second;
                    intervals.push_back({start, i});
                    stack.pop_back();
                }
            }
        }

        for (int i = 0; i < intervals.size(); i++) {
            for (int j = i + 1; j < intervals.size(); j++) {
                if (intervals[i].second + 1 == intervals[j].first) {
                    intervals[i].second = intervals[j].second;
                    intervals[j].first = INT_MIN;
                    intervals[j].second = INT_MIN;
                }
            }
        }

        int max_len = 0;
        for (const auto& interval : intervals) {
            if (interval.first != INT_MIN) {
                max_len = max(max_len, interval.second - interval.first + 1);
            }
        }

        return max_len;
    }
};

int main() {
    string s = "(()())";
    Solution sol;
    int output = sol.longestValidParentheses(s);

    cout << output << endl;

    return 0;
}
