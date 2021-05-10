class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int M = text1.size(), N = text2.size();
        int DP[M + 1][N + 1];
        for (int i=0; i<=M; i++) {
            for (int j=0; j<=N; j++) {
                if (i == 0 || j == 0) DP[i][j] = 0;
                else if (text1[i - 1] == text2[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
                else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
        return DP[M][N];
    }
};