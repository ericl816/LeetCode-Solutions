class Solution {
public:
    
    vector<int> adj[110][2];
    int dist[110][2];
    queue<pair<int, int> > q;
    bool vis[110][2];
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<2; j++) {
                dist[i][j] = 0x3f3f3f3f;
            }
        }
        for (auto i : red_edges) {
            adj[i[0]][0].push_back(i[1]);
        }
        for (auto i : blue_edges) {
            adj[i[0]][1].push_back(i[1]);
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<2; j++) {
                vector<int> next = adj[i][j];
                sort(next.begin(), next.end());
                next.erase(unique(next.begin(), next.end()), next.end());
            }
        }
        dist[0][0] = dist[0][1] = 0;
        q.push(make_pair(0, 0)), q.push(make_pair(0, 1));
        vis[0][0] = vis[0][1] = 1;
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (auto i : adj[curr.first][curr.second ^ 1]) {
                if (!vis[i][curr.second ^ 1]) {
                    dist[i][curr.second ^ 1] = dist[curr.first][curr.second] + 1;
                    vis[i][curr.second ^ 1] = 1;
                    q.push(make_pair(i, curr.second ^ 1));
                }
            }
        }
        vector<int> ans;
        for (int i=0; i<n; i++) {
            int minn = min(dist[i][0], dist[i][1]);
            ans.push_back(minn == 0x3f3f3f3f ? -1 : minn);
        }
        return ans;
    }
};