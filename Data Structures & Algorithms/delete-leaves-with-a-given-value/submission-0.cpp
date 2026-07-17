/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* dfs(TreeNode* node, int target) {
        if (node->left)
            node->left = dfs(node->left, target);
        if (node->right)
            node->right = dfs(node->right, target);
        if (!node->left && !node->right && node->val == target) {
            return nullptr;
        }
        return node;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        root = dfs(root, target);
        return root;
    }
};