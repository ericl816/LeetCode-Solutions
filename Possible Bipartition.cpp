class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int colour[N + 1];
        memset(colour, 0, sizeof(colour));
        map<int, vector<int>> adj;
        for (auto i : dislikes) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        for (auto i : adj) {
            if (colour[i.first] == 0) {
                colour[i.first] = 1;
                q.push(i.first);
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    for (auto next : adj[curr]) {
                        if (colour[next] == 0) {
                            colour[next] = -1 * colour[curr];
                            q.push(next);
                        }
                        else if (colour[next] != -1 * colour[curr]) return 0;
                    }
                }
            }
        }
        return 1;
    }
};