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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> trk(2); // first index will be passing k to function second will be ret
        trk[0] = k;
        dfs(root, trk);
        return trk[1];
    }

    void dfs(TreeNode* curr, vector<int>& temp){
        if (!curr){
            return;
        }
        dfs(curr->left, temp);
        if (temp[0] == 0){
            return;
        }
        
        temp[0]--;
        if (temp[0] == 0){
            temp[1] = curr->val;
            return;
        }

        dfs(curr->right, temp);
    }
};
