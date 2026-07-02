class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> trk;
        int l(0), ret(0);

        for (int r = 0; r < s.size(); ++r) {
            if (trk.find(s[r]) != trk.end()) {
                l = std::max(l, trk[s[r]] + 1);
            }
            trk[s[r]] = r;
            ret = std::max(ret, r - l + 1);
        }
        return ret;

    }
};
