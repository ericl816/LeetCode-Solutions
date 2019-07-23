class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int DP[nums.size() + 1];
        int ans = nums[0];
        DP[0] = nums[0];
        for (size_t i=1; i<nums.size(); i++) {
            DP[i] = max(nums[i], DP[i - 1] + nums[i]);
            ans = max(ans, DP[i]);
        }
        return ans;
        // return maxSubArray(nums, 0, nums.size() - 1);
    }

    int maxSubArray (vector<int> &nums, int l, int r) {
        if (l == r) return nums[l];
        int mid = (l + r) >> 1;
        int lmid = nums[mid], rmid = nums[mid + 1];
        int lmax = maxSubArray(nums, l, mid);
        int rmax = maxSubArray(nums, mid + 1, r);
        for (int i=mid, sum=0; i>=l; i--) {
            sum += nums[i];
            lmid = max(lmid, sum);
        }
        for (int i=mid + 1, sum=0; i<=r; i++) {
            sum += nums[i];
            rmid = max(rmid, sum);
        }
        return max(max(lmax, rmax), lmid + rmid);
    }
};