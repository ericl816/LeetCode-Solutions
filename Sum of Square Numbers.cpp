class Solution {
public:
    
    bool judgeSquareSum(int c) {
        long long lo = 0, hi = sqrt(c);
        while (lo <= hi) {
            if (lo * lo + hi * hi == c) return 1;
            else if (lo * lo + hi * hi > c) hi--;
            else lo++;
        }
        return 0;
    }
};