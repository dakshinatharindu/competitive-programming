#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = n - 1; j > 2; j--) {
                if ((j < n - 1) && nums[j] == nums[j + 1]) continue;

                int left = i + 1;
                int right = j - 1;

                while (left < right) {
                    long int sum = (long int)nums[i] + (long int)nums[left] +
                                   (long int)nums[right] + (long int)nums[j];

                    if (sum == target) {
                        result.push_back(
                            {nums[i], nums[left], nums[right], nums[j]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = solution.fourSum(nums, target);

    cout << "Pairs that sum to " << target << ":\n";
    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << ", " << pair[2] << ", " << pair[3] << "]\n";
    }

    return 0;
}
