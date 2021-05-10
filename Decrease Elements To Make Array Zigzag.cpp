class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int sums[2] = {0, 0};
        for (size_t i=0; i<nums.size(); i++) {
            int l = i == 0 ? 0x3f3f3f3f : nums[i - 1], r = i == nums.size() - 1 ? 0x3f3f3f3f : nums[i + 1];
            if (nums[i] >= min(l, r)) sums[i & 1] += nums[i] - min(l, r) + 1;
        }
        return min(sums[0], sums[1]);
    }
};