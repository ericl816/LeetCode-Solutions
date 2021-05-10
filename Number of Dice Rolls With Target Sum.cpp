class Solution {
public:
    
    int MOD = 1e9 + 7;
    int DP[1010];
    
    int numRollsToTarget(int d, int f, int target) {
        DP[0] = 1;
        while (d--) {
            for (int i=target; i>=0; i--) {
                DP[i] = 0;
                for (int j=1; j<=f; j++) {
                    if (i >= j) DP[i] = (DP[i] + DP[i - j]) % MOD;
                }
            }
        }
        return DP[target];
    }
};