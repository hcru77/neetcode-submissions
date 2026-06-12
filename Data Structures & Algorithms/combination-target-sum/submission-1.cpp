class Solution {
public:

    // Make global variable to be able to append to it during backtracking
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<int> cur;
        backtrack(nums, cur, 0, target);
        return res;
    }

    void backtrack(vector<int> &nums, vector<int> &cur, int ind, int target){
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || ind >= nums.size()) {
            return; 
        }

        cur.push_back(nums[ind]);
        backtrack(nums, cur, ind, target - nums[ind]);
        cur.pop_back();
        backtrack(nums, cur, ind + 1, target);
    }
};
