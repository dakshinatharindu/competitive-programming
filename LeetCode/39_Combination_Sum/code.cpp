#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void findSum(vector<int>& candidates, int target, vector<int>& current, int idx, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
        } else if (target > 0) {
            for (int i = idx; i < candidates.size(); i++) {
                int val = candidates[i];
                current.push_back(val);
                findSum(candidates, target - val, current, i, result);
                current.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        findSum(candidates, target, current, 0, result);

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = solution.combinationSum(candidates, target);

    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
