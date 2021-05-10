class Solution {
public:
    
    void backtrack (vector<vector<int> > &vec, vector<int> temp, vector<int> &candidates, int idx, int target) {
        if (target < 0) return;
        if (target == 0) vec.push_back(temp);
        else {
            for (int i=idx; i<candidates.size(); i++) {
                if (i > idx && candidates[i] == candidates[i - 1]) continue;
                temp.push_back(candidates[i]);
                backtrack(vec, temp, candidates, i + 1, target - candidates[i]);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(ans, temp, candidates, 0, target);
        return ans;
    }
};