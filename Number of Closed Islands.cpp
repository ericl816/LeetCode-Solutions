class Solution {
public:
    
    bool isValid (vector<vector<int> > &grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return 0;
        if (grid[x][y]) return 1;
        grid[x][y] = 1;
        bool a = isValid(grid, x - 1, y), b = isValid(grid, x + 1, y), c = isValid(grid, x, y - 1), d = isValid(grid, x, y + 1);
        return a && b && c && d;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int cnt = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (!grid[i][j] && isValid(grid, i, j)) cnt++;
            }
        }
        return cnt;
    }
};