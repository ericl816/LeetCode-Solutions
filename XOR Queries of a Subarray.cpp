class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        if (arr.empty() || queries.empty()) return ans;
        vector<int> pref;
        pref.reserve(arr.size() + 1);
        pref[0] = arr[0];
        for (int i=1; i<arr.size(); i++) {
            pref[i] = pref[i - 1] ^ arr[i];
        }
        for (auto i : queries) {
            if (i[0]) ans.push_back(pref[i[1]] ^ pref[i[0] - 1]);
            else ans.push_back(pref[i[1]]);
        }
        return ans;
    }
};