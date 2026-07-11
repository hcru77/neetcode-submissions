class Solution {
    vector<int> curQuad;
    vector<vector<int>> res;

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        kSum(nums, 4, 0, (long long) target);
        return res;
    }
private:
    void kSum(vector<int>& nums, int k, int start, long long target) {
        // k is 4 in this case
        if (k != 2) {
            for (int i = start; i < nums.size() - k + 1; ++i) {
                // We have to find the next valid number
                if (i > start && nums[i] == nums[i - 1]) {
                    continue;
                }
                curQuad.push_back(nums[i]);
                kSum(nums, k - 1, i + 1, target - nums[i]);
                curQuad.pop_back();
            }
            return;
        }

        int l = start;
        int r = nums.size() - 1;
        while (l < r) {
            int summ = nums[l] + nums[r];
            if (summ > target) {
                r--;
            }
            else if (summ < target) {
                l++;
            }
            else {
                curQuad.push_back(nums[l]);
                curQuad.push_back(nums[r]);
                res.push_back(curQuad);
                curQuad.pop_back();
                curQuad.pop_back();
                l++;
                r--;
                while (l < r && nums[l] == nums[l - 1]) {
                    l++;
                }
            }
        }
        return;
    }
};