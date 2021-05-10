class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (size_t i=0; i<nums.size(); i++) {
            int lo = 0, hi = i - 1;
            while (lo < hi) {
                if (nums[lo] + nums[hi] > nums[i]) {
                    ans += hi - lo;
                    hi--;
                }
                else lo++;
            }
        }
        return ans;
    }
};