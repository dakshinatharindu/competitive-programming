#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int diff = INT_MAX;
        int closestSum = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target) {
                    return sum; 
                }

                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    closestSum = sum;
                }

                if (sum < target) {
                    left++;
                } else {
                    right--;
                }

            }
        }

        return closestSum;
    }
};

int main() {
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    int target = 1;

    Solution s;
    int result = s.threeSumClosest(input, target);
    cout << "The closest sum is: " << result << endl;

    return 0;
}