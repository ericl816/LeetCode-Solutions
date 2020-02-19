class Solution {
public:
    int minDistance(string word1, string word2) {
        int DP[word1.size() + 1][word2.size() + 1];
        for (int i=0; i<=word1.size(); i++) DP[i][0] = i;
        for (int i=0; i<=word2.size(); i++) DP[0][i] = i;
        for (int i=1; i<=word1.size(); i++) {
            for (int j=1; j<=word2.size(); j++) {
                DP[i][j] = INT_MAX;
                if (word1[i - 1] != word2[j - 1]) {
                    DP[i][j] = min(DP[i][j], DP[i - 1][j] + 1);
                    DP[i][j] = min(DP[i][j], DP[i][j - 1] + 1);
                    DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + 1);
                }
                else DP[i][j] = DP[i - 1][j - 1];
            }
        }
        return DP[word1.size()][word2.size()];
    }
};