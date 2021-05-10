class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<vector<int>> DP(n, vector<int>(n));
        for (int i=n - 1; i>=0; i--) {
            for (int j=i; j<n; j++) {
                for (int k=i; k<=j; k++) {
                    DP[i][j] = max(DP[i][j], nums[k] * (i ? nums[i - 1] : 1) * (j + 1 < n ? nums[j + 1] : 1) + (i <= k - 1 ? DP[i][k - 1] : 0) + (k + 1 <= j ? DP[k + 1][j] : 0));
                }
            }
        }
        return DP[0][n - 1];
    }
};