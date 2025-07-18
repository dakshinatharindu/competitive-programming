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
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {}
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
    return 0;
}