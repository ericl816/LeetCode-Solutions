class Solution {
public:
    
    vector<bool> flag;
    
    int countPrimes(int n) {
        flag.assign(n, 1);
        int cnt = 0;
        for (int i=2; i<n; i++) {
            if (flag[i]) {
                cnt++;
                for (int j=i * 2; j<n; j += i) flag[j] = 0;
            }
        }
        return cnt;
    }
};