#include <climits>
#include <queue>
#include <iostream>

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int max_val = INT_MIN;
        int max_level;
        int level = 0;
        while (!q.empty()) {
            int sum = 0;
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            level++;
            if (sum > max_val) {
                max_val = sum;
                max_level = level;
            }
        }

        return max_level;
    }
};

int main() {
    Solution solution;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    int result = solution.maxLevelSum(root);
    cout << "Maximum level sum is at level: " << result << endl;

    return 0;
}