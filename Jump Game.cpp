class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxx = 0;
        for (int i=0; i<nums.size(); i++) {
            if (i > maxx) return 0;
            maxx = max(maxx, i + nums[i]);
        }
        return 1;
    }
};