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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }

        bool found = false;
        TreeNode* cN = root;

        while (!found)
        {
            if (val > cN->val) {
                if (cN->right) {
                    cN = cN->right;
                }
                else {
                    cN->right = new TreeNode(val);
                    found = true;
                }
            }
            else {
                if (cN->left) {
                    cN = cN->left;
                }
                else {
                    cN->left = new TreeNode(val);
                    found = true;
                }
            }    
        }
        return root;
    }
};