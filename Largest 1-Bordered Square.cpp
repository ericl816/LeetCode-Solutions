class Solution {
public:
    
    int ans, N, M;
    
    bool good (vector<vector<int>>&grid, int x, int y, int len) {
        for (int i=0; i<=len; i++) {
            if (!grid[x + len][y + i] || !grid[x + i][y + len]) return 0;
        }
        return 1;
    }
    
    int check (vector<vector<int>>&grid, int x, int y) {
        int maxx = 1;
        for (int i=0; i<min(N - x, M - y); i++) {
            if (grid[x + i][y] && grid[x][y + i]) {
                if (i >= maxx && good(grid, x, y, i)) maxx = i + 1;
            }
            else break;
        }
        return maxx;
    }
    
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        N = grid.size(), M = grid[0].size();
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (grid[i][j]) ans = max(ans, check(grid, i, j));
            }
        }
        return ans * ans;
    }
};