class Solution {
public:
    
    int N, C, R, i, iMirror, maxLPSLength, maxLPSCenterPosition;
    int L[2010];
    string ans;
    
    inline void Manachers (string text) {
        if (N <= 1) {
            ans = text;
            return;
        }
        N = N << 1 | 1, L[0] = 0, L[1] = 1, C = 1, R = 2;
        int start = -1, end = -1, diff = -1;
        for (i=2; i<N; i++) {
            iMirror = (C << 1) - i;
            L[i] = 0;
            diff = R - i;
            if (diff > 0) L[i] = min(L[iMirror], diff);
            while (((i + L[i]) < N && (i - L[i]) > 0) && (!((i + L[i] + 1) & 1) || (text[(i + L[i] + 1) >> 1] == text[(i - L[i] - 1) >> 1]))) L[i]++;
            if (L[i] > maxLPSLength) {
                maxLPSLength = L[i];
                maxLPSCenterPosition = i;
            }
            if (i + L[i] > R)  {
                C = i;
                R = i + L[i];
            }
        }
        start = (maxLPSCenterPosition - maxLPSLength) >> 1;
        end = start + maxLPSLength - 1;
        for (i=start; i<=end; i++) ans += text[i];
    }
    
    string longestPalindrome(string s) {
        N = s.size();
        Manachers(s);
        return ans;
    }
};