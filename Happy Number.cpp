class Solution {
public:
    int sum (int n) {
        int res = 0;
        while (n) {
            int x = n % 10;
            res += x * x;
            n /= 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = sum(slow);
            fast = sum(fast);
            fast = sum(fast);
            if (slow == 1 || fast == 1) return 1;
        } while (slow ^ fast);
        return slow == 1;
    }
};