#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int dp_i = nums[0];
        int max_val = dp_i;
        for (int i = 1; i < nums.size(); i++) {
            if (dp_i > 0)
                dp_i = dp_i + nums[i];
            else
                dp_i = nums[i];
            max_val = max(dp_i, max_val);
        }
        return max_val;
    }
};

int main() {
    vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    int out = s.maxSubArray(input);
    cout << "Maximum Subarray Sum = " << out << endl;
}
