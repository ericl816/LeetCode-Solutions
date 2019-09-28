class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) return vector<int>{};
        vector<int> left(nums.size());
        left[0] = 1;
        for (int i=1; i<nums.size(); i++) left[i] = left[i - 1] * nums[i - 1];
        int right = 1;
        for (int i=nums.size() - 1; i>=0; i--) {
            left[i] *= right;
            right *= nums[i];
        }
        return left;
    }
};