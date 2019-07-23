class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for (auto i : nums1) nums.push_back(i);
        for (auto i : nums2) nums.push_back(i);
        sort(nums.begin(), nums.end());
        double ans = 0;
        if (nums.size() & 1) ans = nums[nums.size() >> 1];
        else ans = (nums[(nums.size() >> 1) - 1] + nums[nums.size() >> 1]) / 2.0;
        return ans;
    }
};