class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        int DP[n + 1];
        vector<pair<int, pair<int, int> > > vec;
        for (int i=0; i<n; i++) {
            vec.push_back(make_pair(profit[i], make_pair(startTime[i], endTime[i])));
        }
        sort(vec.begin(), vec.end(), [] (const pair<int, pair<int, int> > &a, const pair<int, pair<int, int> > &b) {
            return a.second.second < b.second.second;
        });
        DP[0] = vec[0].first;
        int ans = INT_MIN;
        for (int i=1; i<n; i++) {
            DP[i] = max(DP[i - 1], vec[i].first);
            for (int j=i - 1; j>=0; j--) {
                if (vec[j].second.second <= vec[i].second.first) {
                    DP[i] = max(DP[i], DP[j] + vec[i].first);
                    break;
                }
            }
            ans = max(ans, DP[i]);
        }
        return ans;
    }
};