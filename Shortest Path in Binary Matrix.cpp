class Solution {
public:
    
    int movex[4] = {0, 0, -1, 1};
    int movey[4] = {-1, 1, 0, 0};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1]) return -1;
        queue<pair<int, pair<int, int> > > q;
        q.push(make_pair(1, make_pair(0, 0)));
        while (!q.empty()) {
            pair<int, pair<int, int> > curr = q.front();
            q.pop();
            if (curr.second.first == n - 1 && curr.second.second == n - 1) return curr.first;
            for (int i=0; i<4; i++) {
                for (int j=0; j<4; j++) {
                    int nextx = curr.second.first + movex[i], nexty = curr.second.second + movey[j];
                    if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n && !grid[nextx][nexty]) {
                        grid[nextx][nexty] = 1;
                        q.push(make_pair(curr.first + 1, make_pair(nextx, nexty)));
                    }
                }
            }
        }
        return -1;
    }
};