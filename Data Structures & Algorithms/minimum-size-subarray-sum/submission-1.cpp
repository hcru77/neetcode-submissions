class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l(0);
        int r(0);
        int res(INT_MAX);


        int temp(0);
        while (r < nums.size()) {
            temp += nums[r];

            
            while (temp >= target){
                res = std::min((r - l) + 1, res);
                temp -= nums[l];
                l++;
            }
            r++;
        }
        return res == INT_MAX ? 0 : res;

    }
};