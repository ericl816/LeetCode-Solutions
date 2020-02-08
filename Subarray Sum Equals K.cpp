class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        map<int, int> dict;
        int sum = 0;
        int ans = 0;
        dict[0] = 1;
        for (auto i : nums) {
            sum += i;
            if (dict.count(sum - k)) ans += dict[sum - k];
            dict[sum]++;
        }
        return ans;
    }
};