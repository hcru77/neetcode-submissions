class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size();
        int M = matrix[0].size();

        int hi = 0, lo = N - 1;
        bool res = false;

        // hi = 0
        // lo = 2
        while (hi <= lo) {
            int midV = (hi + lo) / 2;
            if (target > matrix[midV][0] && target > matrix[midV][M - 1]) {
                hi = midV + 1;
            }
            else if (target < matrix[midV][0] && target < matrix[midV][M - 1]) {
                lo = midV - 1;
            }
            else {
                int l = 0, r = M - 1;
                while (l <= r) {
                    int midH = (l + r) / 2;
                    if (matrix[midV][midH] > target) {
                        r = midH - 1;
                    }
                    else if (matrix[midV][midH] < target){
                        l = midH + 1;
                    }
                    else {
                        res = true;
                        break;
                    }
                }
                break;
            }
        }
        return res;
    }
};
