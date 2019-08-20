class Solution {
public:
    
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);
        for (auto i : bookings) {
            diff[i[0] - 1] += i[2];
            if (i[1] < n) diff[i[1]] -= i[2];
        }
        for (int i=1; i<n; i++) diff[i] += diff[i - 1];
        return diff;
    }
};