class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[lo] <= nums[mid]) { // Left half sorted
                if (nums[lo] <= target && target <= nums[mid]) hi = mid - 1;
                else lo = mid + 1;
            }
            else { // Right half sorted
                if (nums[mid] <= target && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        return -1;
    }
};