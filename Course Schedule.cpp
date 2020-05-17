class Solution {
public:
    int vis[100010], indeg[100010];
    vector<int> adj[100010];
    bool flag;
    
    // Solution using DFS graph cycle detection
    void DFS (int node, int prev) {
        vis[node] = 1;
        for (auto i : adj[node]) {
            if (vis[i] == 1) {
                flag = 1;
                return;
            }
            else if (!vis[i]) DFS(i, node);
        }
        vis[node] = 2;
    }

    // Solution using Topological Sort
    bool BFS (int N) {
        for (int i=0; i<N; i++) {
            for (auto j : adj[i]) ++indeg[j];
        }
        queue<int> q;
        for (int i=0; i<N; i++) {
            if (!indeg[i]) q.push(i);
        }
        int cnt = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ++cnt;
            for (auto i : adj[curr]) {
                if (--indeg[i] == 0) q.push(i);
            }
        }
        return cnt == N;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        memset(vis, 0, sizeof(vis));
        for (auto i : prerequisites) adj[i[1]].push_back(i[0]);
        for (int i=0; i<numCourses; i++) {
            if (!vis[i]) DFS(i, -1);
        }
        return !flag;
        // return BFS(numCourses);
    }
};