// Simply count number of connected components
class Solution {
public:
    int N, M;
    bool vis[1010][1010];
    
    void dfs (vector<vector<char> > &grid, int x, int y) {
        if (x >= N || x < 0 || y >= M || y < 0 || vis[x][y] || grid[x][y] == '0') {
            return;
        }
        vis[x][y] = 1;
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        N = grid.size(), M = grid[0].size();
        int cnt = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};