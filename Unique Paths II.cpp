class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long> > DP(m + 1, vector<long long>(n + 1, 0));
        if (obstacleGrid[0][0]) return 0;
        DP[0][1] = 1;
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (obstacleGrid[i - 1][j - 1]) continue;
                DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
            }
        }
        return DP[m][n];
    }
};