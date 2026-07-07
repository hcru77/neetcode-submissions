class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l(0);
        int maxx(0);
        int res(0);


        for (int r = 0; r < s.size(); ++r){
            freq[s[r]]++;
            maxx = std::max(freq[s[r]], maxx);

            if ((r - l + 1 - maxx) > k){ // If the window size - max freq inside window
            // Is greater than k, this means that we are
                freq[s[l]]--;
                l++;
            }

            res = std::max(res, r - l + 1);

        }
        return res;
    }
};
