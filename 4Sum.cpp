class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for (size_t i=0; i<nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (size_t j=i + 1; j<nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum > target) r--;
                    else if (sum < target) l++;
                    else {
                        ans.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        while (l + 1 < r && nums[l] == nums[l + 1]) l++;
                        while (r - 1 > l && nums[r] == nums[r - 1]) r--;
                        l++, r--;
                    }
                }
            }
        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};