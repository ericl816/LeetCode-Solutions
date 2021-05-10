class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> primes{2, 3, 5, 7, 11, 13, 17, 19};
        int cnt = 0;
        for (int i=L; i<=R; i++) cnt += primes.count(__builtin_popcount(i));
        return cnt;
    }
};