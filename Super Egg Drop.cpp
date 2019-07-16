class Solution {
public:
    int DP[10010][110];
    
    int superEggDrop(int K, int N) {
        int num = 0;
        while (DP[num][K] < N) {
            ++num;
            for (int i=1; i<=K; i++) DP[num][i] = DP[num - 1][i - 1] + DP[num - 1][i] + 1;
        }
        return num;
    }
};