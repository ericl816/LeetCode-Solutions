class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int maxx = 0;
        for (int i=0; i<prices.size() - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                maxx += prices[i + 1] - prices[i];
            }
        }
        return maxx;
    }
};