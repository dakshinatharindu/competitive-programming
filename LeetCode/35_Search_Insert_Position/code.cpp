#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;

        if (nums[start] >= target) return start;
        if (nums[end] < target) return end + 1;

        while (end - start != 1) {
            mid = (start + end) / 2;
            if (nums[mid] > target) {
                end = mid;
            } else if (nums[mid] < target) {
                start = mid;
            } else if (nums[mid] == target) {
                return mid;
            }
        }

        return (start + end) / 2 + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << "Insert position: " << solution.searchInsert(nums, target) << endl; // Output: 2

    target = 2;
    cout << "Insert position: " << solution.searchInsert(nums, target) << endl; // Output: 1

    target = 7;
    cout << "Insert position: " << solution.searchInsert(nums, target) << endl; // Output: 4

    target = 0;
    cout << "Insert position: " << solution.searchInsert(nums, target) << endl; // Output: 0

    return 0;
}