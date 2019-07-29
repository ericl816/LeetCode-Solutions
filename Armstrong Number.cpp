class Solution {
public:
    bool isArmstrong(int N) {
        vector<int> digits;
        while (N) {
            digits.push_back(N % 10);
            N /= 10;
        }
        int len = digits.size(), sum = 0;
        for (auto i : digits) {
            int prod = 1;
            for (int j=1; j<=len; j++) prod *= digits[j - 1];
            sum += prod;
        }
        return sum == N;
    }
};