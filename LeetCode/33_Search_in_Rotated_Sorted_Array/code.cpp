#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int binSearch(vector<int>& nums, int target, int start, int end) {
        if (start > end) return -1;
        int mid = (start + end) / 2;
        int mid_val = nums[mid];
        if (mid_val == target) {
            return mid;
        } else if (mid_val < target) {
            return binSearch(nums, target, mid + 1, end);
        } else {
            return binSearch(nums, target, start, mid - 1);
        }
    }

    int findSortedRange(vector<int>& nums, int target, int start, int end) {
        if (start > end) return -1;
        int mid = (start + end) / 2;
        if (nums[start] <= nums[end]) {
            return binSearch(nums, target, start, end);
        }

        if (nums[mid] == target) return mid;

        if (target >= nums[start]) {
            if ((nums[start] <= nums[mid]) && (target > nums[mid])) {
                return findSortedRange(nums, target, mid + 1, end);
            } else {
                return findSortedRange(nums, target, start, mid - 1);
            }
        } else if (target <= nums[end]) {
            if ((nums[end] >= nums[mid]) && (target < nums[mid])) {
                return findSortedRange(nums, target, start, mid - 1);
            } else {
                return findSortedRange(nums, target, mid + 1, end);
            }
        } else
            return -1;
    }

    int search(vector<int>& nums, int target) {
        return findSortedRange(nums, target, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int index = sol.search(nums, 0);
    cout << index << endl;
    return 0;
}
