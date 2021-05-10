class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 100000;
        for (size_t i=0; i<nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(ans - target)) ans = sum;
                if (sum < target) l++;
                else if (sum > target) r--;
                else return ans;
            }
        }
        return ans;
    }
};