class Solution {
public:
    int vis[100010], indeg[100010];
    vector<int> adj[100010];
    vector<int> ans;
    
    // Solution using DFS graph cycle detection
    bool DFS (int node, int prev) {
        vis[node] = -1;
        for (auto i : adj[node]) {
            if (vis[i] == -1 || (!vis[i] && !DFS(i, node))) {
                return 0;
            }
        }
        vis[node] = 1;
        ans.push_back(node);
        return 1;
    }

    // Solution using Topological Sort
    vector<int> BFS (int N) {
        for (int i=0; i<N; i++) {
            for (auto j : adj[i]) ++indeg[j];
        }
        queue<int> q;
        for (int i=0; i<N; i++) {
            if (!indeg[i]) {
                ans.push_back(i);
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ++cnt;
            for (auto i : adj[curr]) {
                if (--indeg[i] == 0) {
                    ans.push_back(i);
                    q.push(i);
                }
            }
        }
        return cnt == N ? ans : vector<int>();
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        memset(vis, 0, sizeof(vis));
        for (auto i : prerequisites) adj[i[1]].push_back(i[0]);
        for (int i=0; i<numCourses; i++) {
            if (!vis[i] && !DFS(i, -1)) {
                return vector<int>();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans.size() == numCourses ? ans : vector<int>();
    }
};