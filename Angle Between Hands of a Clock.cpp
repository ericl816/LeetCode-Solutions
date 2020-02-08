class Solution {
public:
    double angleClock(int hour, int minutes) {
        double res1 = 0.5 * (60 * hour + minutes);
        double res2 = 6.0 * minutes;
        double ans = abs(res2 - res1);
        return min(ans, 360.0 - ans);
    }
};