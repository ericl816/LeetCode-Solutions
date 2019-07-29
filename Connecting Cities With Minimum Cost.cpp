class Solution {
public:
    
    int lead[1010], rank[1010];
    
    void init () {
        for (int i=0; i<=1000; i++) {
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
        if (Merge(x, y)) {
            if (rank[a] > rank[b]) {
                lead[b] = a;
                rank[a] += rank[b];
            }
            else {
                lead[a] = b;
                rank[b] += rank[a];
            }
        }
    }
    
    int minimumCost(int N, vector<vector<int>>& connections) {
        init();
        int cnt = N, ans = 0;
        sort(connections.begin(), connections.end(), [] (const vector<int> &l, const vector<int> &r) {
            return l[2] < r[2];
        });
        for (auto i : connections) {
            if (ds.Merge(i[0], i[1])) {
                ds.Union(i[0], i[1]);
                ans += i[2];
                cnt--;
            }
        }
        if (cnt == 1) return ans;
        return -1;
    }
};