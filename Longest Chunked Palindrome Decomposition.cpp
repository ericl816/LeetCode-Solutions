class Solution {
public:
    
    int N;
    int DP[1010][1010];
    
    int Solve (string text, int l, int r) {
        if (l > r) return 0;
        int &res = DP[l][r];
        if (~res) return res;
        int val = 1;
        for (int i=1; l + i<=r - i + 1; i++) {
            if (text.substr(l, i) == text.substr(r - i + 1, i)) {
                val = max(val, Solve(text, l + i, r - i) + 2);
            }
        }
        return res = val;
    }
    
    int longestDecomposition(string text) {
        N = text.size();
        memset(DP, -1, sizeof(DP));
        return Solve(text, 0, N - 1);
    }
};