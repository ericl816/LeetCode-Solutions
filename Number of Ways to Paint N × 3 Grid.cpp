class Solution {

public:
    int c1 (int s) {
        return (s / 16) % 4;
    }
    
    int c2 (int s) {
        return (s / 4) % 4;
    }
    
    int c3 (int s) {
        return s % 4;
    }
    
    int to_state (int c1, int c2, int c3) {
        return c1 * 16 + c2 * 4 + c3;
    }
    
    int numOfWays (int n) {
        int f[5001][64];
        for (int c1 = 0; c1 < 3; c1++) {
            for (int c2 = 0; c2 < 3; c2++) {
                for (int c3 = 0; c3 < 3; c3++) {
                    if (c1 != c2 && c2 != c3) {
                        f[1][to_state(c1, c2, c3)] = 1;
                    }
                    else {
                        f[1][to_state(c1, c2, c3)] = 0;
                    }
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            for (int c1 = 0; c1 < 3; c1++) {
                for (int c2 = 0; c2 < 3; c2++) {
                    for (int c3 = 0; c3 < 3; c3++) {
                        int s = to_state(c1, c2, c3);
                        f[i][s] = 0;
                        if (c1 != c2 && c2 != c3) {
                            for (int p1 = 0; p1 < 3; p1++) {
                                for (int p2 = 0; p2 < 3; p2++) {
                                    for (int p3 = 0; p3 < 3; p3++) {
                                        if (c1 != p1 && c2 != p2 && c3 != p3) {
                                            f[i][s] = (f[i][s] + f[i - 1][to_state(p1, p2, p3)]) % 1000000007;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int c1 = 0; c1 < 3; c1++) {
            for (int c2 = 0; c2 < 3; c2++) {
                for (int c3 = 0; c3 < 3; c3++) {
                    ans = (ans + f[n][to_state(c1, c2, c3)]) % 1000000007;
                }
            }
        }
        return ans;
    }
};