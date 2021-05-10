class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> freq;
        for (auto i : arr1) freq[i]++;
        vector<int> ans, ans1;
        map<int, bool> dict;
        for (auto i : arr2) {
            dict[i] = 1;
            int res = freq[i];
            while (res--) ans.push_back(i);
        }
        for (auto i : arr1) {
            if (!dict[i]) ans1.push_back(i);
        }
        sort(ans1.begin(), ans1.end());
        for (auto i : ans1) ans.push_back(i);
        return ans;
    }
};