class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, ans = 0;
        while (i < n && j < n) {
            int diff = abs(nums[i] - nums[j]);
            if (diff > k) i++;
            else if (diff < k) j++;
            else {
                i++, j++, ans++;
                while (i < n && nums[i - 1] == nums[i]) i++;
                while (j < n && nums[j - 1] == nums[j]) j++;
            }
            if (i == j) j++;
        }
        return ans;
    }
};