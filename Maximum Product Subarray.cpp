class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int maxx = 0, minn = 0, ans = 0;
        for (size_t i=0; i<nums.size(); i++) {
            if (nums[i] < 0) swap(maxx, minn);
            maxx = max(nums[i], nums[i] * maxx);
            minn = min(nums[i], nums[i] * minn);
            ans = max(ans, maxx);
        }
        return ans;
    }
};