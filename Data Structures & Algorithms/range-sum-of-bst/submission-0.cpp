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

    void inOrder(TreeNode* node, int low, int high) {
        if (node->left) 
            inOrder(node->left, low, high);
        if (node->val >= low && node->val <= high) {
            res += node->val;
        }
        if (node->right)
            inOrder(node->right, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        inOrder(root, low, high);
        return res;
    }
};