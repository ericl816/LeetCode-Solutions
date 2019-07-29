class Solution {
public:

	void backtrack (vector<vector<int> > &vec, vector<int> temp, vector<int> &nums) {
		if (temp.size() == nums.size()) vec.push_back(temp);
		else {
			for (size_t i=0; i<nums.size(); i++) {
				if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
				temp.push_back(nums[i]);
				backtrack(vec, temp, nums);
				temp.pop_back();
			}
		}
	}

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> temp;
        if (nums.empty()) return ans;
        sort(nums.begin(), nums.end());
        backtrack(ans, temp, nums);
        /*
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        */
        return ans;
    }
};