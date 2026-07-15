class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;

        for (int& a : asteroids) {
            if (a > 0) {
                ret.push_back(a);
            }
            else {
                while (!ret.empty() && ret.back() > 0 && a < 0) {
                    int diff = a + ret.back();
                    if (diff < 0) {
                        ret.pop_back();
                    }
                    else if (diff > 0) {
                        a = 0;
                    }
                    else {
                        ret.pop_back();
                        a = 0;
                    }
                }
                if (a != 0) {
                    ret.push_back(a);
                }
            }
        }
        return ret;
    }
};