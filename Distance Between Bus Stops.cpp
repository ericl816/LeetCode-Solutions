class Solution {
public:

    // SSSP
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        vector<pair<int, int> > adj[distance.size() + 1];
        int n = distance.size();
        for (int i=0; i<n; i++) {
            int j = (i + 1) % n;
            adj[i].push_back(make_pair(j, distance[i]));
            adj[j].push_back(make_pair(i, distance[i]));
        }
        queue<int> q;
        vector<int> dist(distance.size() + 1, 0x3f3f3f3f);
        vector<bool> vis(distance.size() + 1, 0);
        q.push(start);
        dist[start] = 0;
        vis[start] = 1;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            vis[curr] = 0;
            for (auto i : adj[curr]) {
                if (dist[i.first] > dist[curr] + i.second) {
                    dist[i.first] = dist[curr] + i.second;
                    if (!vis[i.first]) {
                        vis[i.first] = 1;
                        q.push(i.first);
                    }
                }
            }
        }
        return dist[destination];
    }

    // Dijkstra
    int distanceBetweenBusStops1 (vector<int>& distance, int start, int destination) {
        vector<pair<int, int> > adj[distance.size() + 1];
        int n = distance.size();
        for (int i=0; i<n; i++) {
            int j = (i + 1) % n;
            adj[i].push_back(make_pair(j, distance[i]));
            adj[j].push_back(make_pair(i, distance[i]));
        }
        priority_queue<pair<int, int> > pq;
        vector<int> dist(distance.size() + 1, 0x3f3f3f3f);
        pq.push(make_pair(0, start));
        dist[start] = 0;
        while (!pq.empty()) {
            pair<int, int> curr = pq.top(); pq.pop();
            if (curr.first > dist[curr.second]) continue;
            for (auto i : adj[curr.second]) {
                if (dist[i.first] > dist[curr.second] + i.second) {
                    dist[i.first] = dist[curr.second] + i.second;
                    pq.push(make_pair(dist[i.first], i.first));
                }
            }
        }
        return dist[destination];
    }
};