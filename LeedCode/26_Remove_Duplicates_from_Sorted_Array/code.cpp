#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, prev = -101;

        for (int i = 0; i < nums.size(); i++) {
            if (prev != nums[i]) {
                nums[k] = nums[i];
                k++;
                prev = nums[i];
            }
            
        }

        return k;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2, 3, 3, 4};

    int k = s.removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "Unique elements: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}