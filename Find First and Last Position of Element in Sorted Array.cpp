class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};
        if (nums.empty()) return ans;
        int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (lo == -1 || lo == nums.size() || nums[lo] ^ target) return ans;
        int hi = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        ans[0] = lo, ans[1] = hi;
        return ans;
    }
};