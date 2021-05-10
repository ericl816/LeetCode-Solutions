class Solution {
public:
    
    void backtrack (vector<vector<int> > &vec, vector<int> temp, vector<int> &candidates, int idx, int target) {
        if (target < 0) return;
        if (target == 0) vec.push_back(temp);
        else {
            for (int i=idx; i<candidates.size(); i++) {
                temp.push_back(candidates[i]);
                backtrack(vec, temp, candidates, i, target - candidates[i]);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(ans, temp, candidates, 0, target);
        return ans;
    }
};