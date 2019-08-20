class Solution {
public:
    
    int n, ans;
    int movex[4] = {0, 0, -1, 1};
    int movey[4] = {-1, 1, 0, 0};
    queue<pair<int, int> > q;
    int dist[110][110];
    
    bool Valid (int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < n;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        memset(dist, -1, sizeof(dist));
        n = grid.size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]) {
                    dist[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i=0; i<4; i++) {
                int x = curr.first + movex[i], y = curr.second + movey[i];
                if (!Valid(x, y) || ~dist[x][y]) continue;
                dist[x][y] = dist[curr.first][curr.second] + 1;
                q.push(make_pair(x, y));
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                ans = max(ans, dist[i][j]);
            }
        }
        return ans ? ans : -1;
    }
};