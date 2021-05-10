class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> freq;
        int ans = 0;
        for (auto i : dominoes) {
            if (i[0] > i[1]) swap(i[0], i[1]);
            freq[make_pair(i[0], i[1])]++;
        }
        for (auto i : freq) ans += (i.second - 1) * i.second / 2;
        return ans;
    }
};