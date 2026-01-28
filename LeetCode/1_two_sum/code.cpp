#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {        

        vector<pair<int, int>> array;
        for (int i = 0; i < nums.size(); i++) {
            array.push_back(make_pair(nums[i], i));
        }

        sort(array.begin(), array.end());
        int i = 0;
        int j = array.size() - 1;
        vector<int> result;
        while (i < j) {
            int sum = array[i].first + array[j].first;
            if (sum == target) {
                result.push_back(array[i].second);
                result.push_back(array[j].second);
                break;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = s.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    cout << "Hello World" << endl;
}