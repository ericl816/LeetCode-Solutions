class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        if (!n && !m) {
        	return 1;
        } else if (!m) {
        	return 0;
        }
        vector<vector<bool> > DP(n + 1, vector<bool>(m + 1, 0));
        DP[0][0] = 1;
        for (int i=2; i<=m; i++) {
        	if (p[i - 1] == '*') {
        		DP[0][i] = DP[0][i - 2];
        	}
        }
        for (int i=1; i<=n; i++) {
        	for (int j=1; j<=m; j++) {
        		if (j > 1 && p[j - 1] == '*') {
        			if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
        				DP[i][j] = DP[i - 1][j] || DP[i][j - 1];
        			}
        			DP[i][j] = DP[i][j] || DP[i][j - 2];
        		} else if (p[j - 1] == '.' || s[i - 1] == p[j - 1]) {
        			DP[i][j] = DP[i - 1][j - 1];
        		}
        	}
        }
        return DP[n][m];
    }
};