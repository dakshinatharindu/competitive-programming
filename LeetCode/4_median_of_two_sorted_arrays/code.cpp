#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int median, median_next;
        while ((i + j) <= (nums1.size() + nums2.size()) / 2) {
            median_next = median;
            if ((i < nums1.size()) && (j < nums2.size())) {
                if (nums1[i] <= nums2[j]) {
                    median = nums1[i];
                    i++;
                } else {
                    median = nums2[j];
                    j++;
                }
            } else if (i < nums1.size()) {
                median = nums1[i];
                i++;
            } else {
                median = nums2[j];
                j++;
            }
        }

        return (nums1.size() + nums2.size()) % 2 == 0
                   ? ((double)median + (double)median_next) / 2
                   : (double)median;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}