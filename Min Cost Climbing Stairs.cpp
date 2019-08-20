class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int DP[cost.size() + 1];
        DP[0] = cost[0], DP[1] = cost[1];
        for (size_t i=2; i<cost.size(); i++) {
            DP[i] = cost[i] + min(DP[i - 1], DP[i - 2]);
        }
        return min(DP[cost.size() - 1], DP[cost.size() - 2]);
    }
};