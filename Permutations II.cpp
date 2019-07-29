class Solution {
public:
    
    void backtrack (vector<vector<int> > &vec, vector<int> temp, vector<int> &nums, bool flag[]) {
        if (temp.size() == nums.size()) vec.push_back(temp);
        else {
            for (size_t i=0; i<nums.size(); i++) {
                if (flag[i] || i > 0 && nums[i] == nums[i - 1] && !flag[i - 1]) continue;
                flag[i] = 1;
                temp.push_back(nums[i]);
                backtrack(vec, temp, nums, flag);
                flag[i] = 0;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> temp;
        bool flag[nums.size() + 1];
        sort(nums.begin(), nums.end());
        backtrack(ans, temp, nums, flag);
        return ans;
    }
};