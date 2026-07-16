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
    int res = 0;

    void dfs(TreeNode* node, int maxx) {
        if (node->val >= maxx) {
            res += 1;
            maxx = node->val;
        }

        if (node->left) 
            dfs(node->left, maxx);
        if (node->right)
            dfs(node->right, maxx);
    }

    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return res;
    }
};
