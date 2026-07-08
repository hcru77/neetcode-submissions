class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        long long timer(0);
        long long summ(0);

        for (auto& c : customers) {
            int arrival = c[0];
            int order = c[1];
            timer = std::max(timer, (long long)arrival) + order;
            summ += (timer - arrival);
        }
        return (double) summ / customers.size();
    }
};