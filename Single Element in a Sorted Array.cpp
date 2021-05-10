class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (mid & 1) {
                if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) lo = mid + 1;
                else hi = mid - 1;
            }
            else {
                if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) lo = mid + 2;
                else hi = mid - 1;
            }
        }
        return nums[lo];
    }
};