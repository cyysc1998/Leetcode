class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profit(prices.size());
        int cur_min = prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            profit[i] = max(profit[i - 1], prices[i] - cur_min);
            cur_min = min(cur_min, prices[i]);
        }
        return profit[prices.size() - 1];
    }
};
