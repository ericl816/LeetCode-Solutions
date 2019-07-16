class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        set<int> ss;
        map<int, int> freq;
        for (auto i : nums) freq[i]++;
        int missing = 0, twice = 0;
        for (auto i : freq) {
            if (i.second == 2) twice = i.first;
        }
        for (int i=1; i<=n; i++) if (freq[i] == 0) missing = i;
        vector<int> ans;
        ans.push_back(twice);
        ans.push_back(missing);
        return ans;
    }
};