class Solution {
public:
    bool isPerfectSquare(int num) {
        double res = sqrt(num);
        return (int) res == res;
    }
};