#include <climits>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    long int res = 0;
    long int totalSum;

    void calcAccSum(TreeNode* node) {
        if (node == nullptr) return;

        calcAccSum(node->left);
        calcAccSum(node->right);

        if (node->left != nullptr) node->val += node->left->val;
        if (node->right != nullptr) node->val += node->right->val;
    }

    void findMaxSum(TreeNode* node) {
        if (node == nullptr) return;

        findMaxSum(node->left);
        findMaxSum(node->right);

        if (node->left != nullptr) {
            res = max(res, node->left->val * (totalSum - node->left->val));
        }
        if (node->right != nullptr) {
            res = max(res, node->right->val * (totalSum - node->right->val));
        }
    }

    int maxProduct(TreeNode* root) {
        calcAccSum(root);
        totalSum = root->val;
        findMaxSum(root);
        return (res % 1000000007);
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;
    cout << sol.maxProduct(root) << endl;

    // Clean up memory (not shown)
    return 0;
}