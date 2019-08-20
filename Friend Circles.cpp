struct Disjoint {
private:
    int N;
    vector<int> lead, rank;

public:
    Disjoint (int N) : N(N + 1), lead(N + 1), rank(N + 1) { }
    
    void Init () {
        for (int i=0; i<N; i++) {
            lead[i] = i;
            rank[i] = 0;
        }
    }
    
    int Find (int x) {
        while (lead[x] ^ x) {
            lead[x] = lead[lead[x]];
            x = lead[x];
        }
        return x;
    }
    
    bool Merge (int x, int y) {
        return Find(x) ^ Find(y);
    }
    
    void Union (int x, int y) {
        int a = Find(x), b = Find(y);
        if (rank[a] > rank[b]) {
            lead[b] = a;
            rank[a] += rank[b];
        }
        else {
            lead[a] = b;
            rank[b] += rank[a];
        }
    }
} ds(210);

class Solution {
public:
    
    vector<bool> vis;
    int ans;
    
    void DFS (int i, int n, vector<vector<int> > &M) {
        if (vis[i]) return;
        vis[i] = 1;
        for (int j=0; j<n; j++) {
            if (i ^ j && !vis[j] && M[i][j]) DFS(j, n, M);
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        ds.Init();
        int ans = n;
        for (int i=0; i<n; i++) {
            for (int j=i + 1; j<n; j++) {
                if (M[i][j]) {
                    if (ds.Merge(i, j)) {
                        ds.Union(i, j);
                        ans--;
                    }
                }
            }
        }
        return ans;
    }

    // DFS Solution: O(N^2) time and O(N) space complexity
    int findCircleNum1 (vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        vis.assign(n + 1, 0);
        for (int i=0; i<n; i++) {
            if (vis[i]) continue;
            DFS(i, n, M);
            ans++;
        }
        return ans;
    }
};