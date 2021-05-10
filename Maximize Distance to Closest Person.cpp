class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int prevv = -1, ans = 0;
        for (int i=0; i<seats.size(); i++) {
            if (!seats[i]) continue;
            if (prevv < 0) ans = i;
            else ans = max(ans, (i - prevv) / 2);
            prevv = i;
        }
        return max(ans, (int) seats.size() - prevv - 1);
    }
};