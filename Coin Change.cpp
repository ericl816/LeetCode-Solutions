class Solution {
public:
    
    vector<int> DP;
    
    int coinChange(vector<int>& coins, int amount) {
        DP.assign(amount + 1, 0x3f3f3f3f);
        DP[0] = 0;
        for (int i=1; i<=amount; i++) {
            for (size_t j=0; j<coins.size(); j++) {
                if (i >= coins[j]) DP[i] = min(DP[i], DP[i - coins[j]] + 1);
            }
        }
        return DP[amount] == 0x3f3f3f3f ? -1 : DP[amount];
    }
};