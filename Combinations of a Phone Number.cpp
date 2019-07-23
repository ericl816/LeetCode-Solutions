class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int, string> dict = { {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"} };
        vector<string> ans;
        if (digits.empty()) return ans;
        ans.push_back("");
        for (size_t i=0; i<digits.size(); i++) {
            int num = (int) digits[i] - '0';
            string s = dict[num];
            vector<string> vec;
            for (size_t j=0; j<s.size(); j++) {
                for (size_t k=0; k<ans.size(); k++) {
                    vec.push_back(ans[k] + s[j]);
                }
            }
            ans = vec;
        }
        return ans;
    }
};