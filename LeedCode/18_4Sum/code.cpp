#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int first = 0;
        int last = nums.size() - 1;
        vector<vector<int>> out;

        while (first < last) {
            if (nums[first] + nums[last] == target) {
                out.push_back({nums[first], nums[last]});
                break;
            } else if (nums[first] + nums[last] < target) {
                first++;
            } else {
                last--;
            }
        }

        return out;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = solution.fourSum(nums, target);

    cout << "Pairs that sum to " << target << ":\n";
    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "]\n";
    }

    return 0;
}
