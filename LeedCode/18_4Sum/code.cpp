#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;

        int a = 0;
        int b = nums.size() - 1;

        int ptarget;
        while (a < b) {
            ptarget = target - nums[a] - nums[b];
            int first = a + 1;
            int last = b - 1;

            while (first < last) {
                if (nums[first] + nums[last] == ptarget) {
                    out.push_back({nums[a], nums[first], nums[last], nums[b]});
                    break;
                } else if (nums[first] + nums[last] < target) {
                    first++;
                } else {
                    last--;
                }
            }

            while (a < b && nums[a] == nums[a + 1]) {
                a++;
            }
            while (a < b && nums[b] == nums[b - 1]) {
                b--;
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
