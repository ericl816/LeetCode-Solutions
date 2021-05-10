class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
    	int maxx = 0, buy = prices[0];
    	for (auto i : prices) {
    		if (buy > i) buy = i;
    		else if (i - buy > maxx) maxx = i - buy;
    	}
    	return maxx;
    }
};