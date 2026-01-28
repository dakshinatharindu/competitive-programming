#include <iostream>
#include <vector>
#include <algorithm>

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
                    findSum(candidates, target - val, current, i + 1, result);
                    current.pop_back();

                    while ((i + 1 < candidates.size()) && (candidates[i] == candidates[i+1])) {
                        i++;
                    }
                }
            }
        }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        findSum(candidates, target, current, 0, result);

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = solution.combinationSum2(candidates, target);

    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
