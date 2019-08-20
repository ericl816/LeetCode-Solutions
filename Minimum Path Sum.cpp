class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i == 0 && j == 0) continue;
                int x = i == 0 ? 0x3f3f3f3f : grid[i - 1][j];
                int y = j == 0 ? 0x3f3f3f3f : grid[i][j - 1];
                grid[i][j] += min(x, y);
            }
        }
        return grid[n - 1][m - 1];
    }
};