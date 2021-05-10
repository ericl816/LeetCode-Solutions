class Solution {
public:
    int rob(vector<int>& nums) {
        if (!nums.size()) return 0;
        int DP[nums.size() + 1];
        DP[0] = 0;
        DP[1] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            DP[i + 1] = max(DP[i], nums[i] + DP[i - 1]);
        }
        return DP[nums.size()];
    }
};