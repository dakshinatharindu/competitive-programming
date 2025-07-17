#include <iostream>
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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr)
            return false;
        else if ((root->left == nullptr) && (root->right == nullptr) && (root->val == targetSum))
            return true;
        else {
            return hasPathSum(root->left, targetSum - root->val)
                       ? true
                       : hasPathSum(root->right, targetSum - root->val);
        }
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
    bool result = solution.hasPathSum(root, targetSum);

    // Clean up memory (not shown here)
    
    std::cout << "Has path sum: " << (result ? "true" : "false") << std::endl;
    return 0;
}