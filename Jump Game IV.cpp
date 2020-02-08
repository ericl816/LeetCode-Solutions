class Solution {
public:
    int minJumps(vector<int>& arr) {
        if (arr.empty()) return 0;
        map<int, vector<int> > equal;
        int n = arr.size();
        int dist[n + 1];
        bool vis[n + 1];
        queue<int> q;
        memset(dist, -1, sizeof(dist));
        dist[0] = 0;
        vis[0] = 1;
        q.push(0);
        for (int i=0; i<n; i++) {
            equal[arr[i]].push_back(i);
        }
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            if (curr == n - 1) {
                return dist[curr];
            }
            for (auto i : equal[arr[curr]]) {
                if (dist[i] == -1) {
                    dist[i] = dist[curr] + 1;
                    q.push(i);
                }
            }
            equal[arr[curr]].clear();
            if (curr + 1 < n) {
                if (dist[curr + 1] == -1) {
                    dist[curr + 1] = dist[curr] + 1;
                    q.push(curr + 1);
                }
            }
            if (curr > 0) {
                if (dist[curr - 1] == -1) {
                    dist[curr - 1] = dist[curr] + 1;
                    q.push(curr - 1);
                }
            }
        }
        return -1;
    }
};