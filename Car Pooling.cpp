class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> diff;
        for (auto i : trips) {
            diff[i[1]] += i[0];
            diff[i[2]] -= i[0];
        }
        for (auto i : diff) {
            capacity -= i.second;
            if (capacity < 0) return 0;
        }
        return 1;
    }
};