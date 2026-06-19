class Solution {
public:
    int search(vector<int>& nums, int target) {
        // In this one you have to check in which half it is, 
        // Checking one side isn't sufficient becuase if 5 < 6, any number
        // < 6 can be both in the left and in the right of 6

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m =  l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (nums[l] <= nums[m]){
                if (target > nums[m] || target < nums[l]){
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            else{
                if (target < nums[m] || target > nums[r]) {
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
            }           
        }
        return -1;

    }
};
