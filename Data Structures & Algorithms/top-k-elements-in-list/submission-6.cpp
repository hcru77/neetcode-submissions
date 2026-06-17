class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Keep track of the frequency of each element
        unordered_map<int, int> freq;
        for (auto n : nums) {
            freq[n]++;
        }

        vector<vector<int>> trk(nums.size()); // 6 spots
        for (auto i : freq) {
            trk[i.second - 1].push_back(i.first);
        }

        vector<int> ret;
        for (int i = trk.size() - 1; i > -1; --i){
            for (auto n : trk[i]){
                ret.push_back(n);
                if (ret.size() == k){
                    return ret;
                }
            }
        }
        return ret;

    }
};
