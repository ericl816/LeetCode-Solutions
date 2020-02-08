class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        int sum_l = 0;
        int sum_r = 0;
        for (auto i : nums) sum_r += i;
        for (int i=0; i<nums.size(); i++) {
            sum_l += nums[i];
            sum_r -= nums[i];
            if (sum_l == sum_r + nums[i]) return i;
        }
        return -1;
    }
};