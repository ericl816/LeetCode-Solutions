class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        int count = 1;
        int idx = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == nums[idx]) count++;
            else count--;
            if (count == 0) {
                idx = i;
                count = 1;
            }
        }
        return nums[idx];
    }
};