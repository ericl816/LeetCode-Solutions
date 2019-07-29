class Solution {
public:
    
    void backtrack (vector<vector<int> > &vec, vector<int> temp, vector<int> &nums, int idx) {
        vec.push_back(temp);
        for (size_t i=idx; i<nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            backtrack(vec, temp, nums, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backtrack(ans, temp, nums, 0);
        return ans;
    }
};