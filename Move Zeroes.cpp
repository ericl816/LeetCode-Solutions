class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        int cnt = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]) {
                nums[cnt++] = nums[i];
            }
        }
        while (cnt < nums.size()) {
            nums[cnt++] = 0;
        }
    }
};