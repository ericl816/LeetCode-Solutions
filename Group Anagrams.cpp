class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > dict;
        for (string i : strs) {
            string str = i;
            sort(str.begin(), str.end());
            dict[str].push_back(i);
        }
        vector<vector<string> > ans;
        for (auto i : dict) {
            ans.push_back(i.second);
        }
        return ans;
    }
};