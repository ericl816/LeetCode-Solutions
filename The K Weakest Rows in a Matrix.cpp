class Solution {
public:
    
    int count_row(vector<int> &row) {
        int count = 0;
        for (auto i : row) count += (i == 1);
        return count;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        if (mat.empty()) return vector<int>{};
        vector<pair<int, int> > rows;
        int m = mat.size();
        int n = mat[0].size();
        for (int i=0; i<m; i++) {
            vector<int> row = mat[i];
            int count = count_row(row);
            rows.push_back(make_pair(count, i));
        }
        sort(rows.begin(), rows.end(), [] (const pair<int, int> &a, pair<int, int> &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        vector<int> ans;
        for (int i=0; i<k; i++) ans.push_back(rows[i].second);
        return ans;
    }
};