class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int DP[A.size() + 1][B.size() + 1];
        for (int i=0; i<=A.size(); i++) {
            for (int j=0; j<=B.size(); j++) {
                if (!i || !j) DP[i][j] = 0;
                else if (A[i - 1] == B[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
                else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
        return DP[A.size()][B.size()];
    }
};