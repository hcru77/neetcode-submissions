class Solution {
public:
    int findMin(vector<int> &nums) {
        int l(0), r(nums.size() - 1);

        int minn(nums[0]);

        while (l <= r) {
            if (nums[l] < nums[r]){
                minn = min(minn, nums[l]);
                break;
            }

            int mid = (l + r) / 2;

            if (nums[mid] >= nums[r]) { 
                l = mid + 1;             
            }
            else{
                r = mid;
            }
            minn = min(minn, nums[mid]);
        }
        return minn;

    }
};
