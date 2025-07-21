#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    void findPaths(TreeNode *root, int targetSum, vector<int> &currentPath, vector<vector<int>> &result) {
        if (root == nullptr) {
            return;
        } else if ((root->left == nullptr) && (root->right == nullptr) && (root->val == targetSum)) {
            currentPath.push_back(targetSum);
            result.push_back(currentPath);
            currentPath.pop_back();
        } else {
            currentPath.push_back(root->val);
            findPaths(root->left, targetSum - root->val, currentPath, result);
            findPaths(root->right, targetSum - root->val, currentPath, result);
            currentPath.pop_back();
        }

    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        findPaths(root, targetSum, currentPath, result);
        return result;

    }
};

int main() {
    // Example usage of the Solution class
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11, new TreeNode(7), new TreeNode(2));
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4, nullptr, new TreeNode(1));

    Solution solution;
    int targetSum = 22;
    vector<vector<int>> result = solution.pathSum(root, targetSum);

    // Clean up memory (not shown here)

    std::cout << "Paths with sum " << targetSum << ": " << result.size() << std::endl;
    for (const auto &path : result) {
        std::cout << "Path: ";
        for (int val : path) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}