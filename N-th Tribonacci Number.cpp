class Solution {
public:
    
    long long fib[40];
    
    int tribonacci(int n) {
        fib[0] = 0, fib[1] = 1, fib[2] = 1;
        for (int i=3; i<=37; i++) fib[i] = fib[i - 1] + fib[i - 2] + fib[i - 3];
        return fib[n];
    }
};