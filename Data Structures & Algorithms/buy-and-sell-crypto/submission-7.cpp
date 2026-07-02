class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l(0), r(0), maxx(0);
        
        while (r < prices.size()) {
            if (prices[r] < prices[l]) {
                l = r;
            }
            else {
                maxx = std::max(prices[r] - prices[l], maxx);
            }
            ++r;
        }
        return maxx;

    }
};
