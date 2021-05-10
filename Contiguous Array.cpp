class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_map<int, int> dict;
        dict[0] = -1;
        int cnt = 0, maxx = 0;
        for (int i=0; i<nums.size(); i++) {
            cnt += nums[i] ? 1 : -1;
            if (dict.count(cnt)) maxx = max(maxx, i - dict[cnt]);
            else dict[cnt] = i;
        }
        return maxx;
    }
};