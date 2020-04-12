class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        int pivot = 1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[lo++]);
            }
        }
        for (int i=nums.size() - 1; i>=0; i--) {
            if (nums[i] > pivot) {
                swap(nums[i], nums[hi--]);
            }
        }
    }
};