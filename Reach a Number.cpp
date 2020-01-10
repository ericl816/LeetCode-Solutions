class Solution {
public:
    int reachNumber(int target) {
        if (target == 0) return 0;
        int sum = 0, step = 0;
        while (sum < target) sum += ++step;
        while ((sum - target) & 1) sum += ++step;
        return step;
    }
};