class Solution {
public:
    
    int n;
    int PSA[101];
    int DP[101][101];
    
    int solve (int x, int M) {
        if (n <= x + M << 1) return PSA[x];
        int &res = DP[x][M];
        if (~res) return res;
        int maxx = 0;
        for (int i=1; i<=M << 1; i++) maxx = max(maxx, PSA[x] - solve(x + i, max(i, M)));
        return res = maxx;
    }
    
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(DP, -1, sizeof(DP));
        int sum = 0;
        for (int i=n - 1; i>=0; i--) {
            sum += piles[i];
            PSA[i] = sum;
        }
        return solve(0, 1);
    }
};