class Solution {
public:
    
    bool isPalindrome (string s, int l, int r) {
        while (l <= r) {
            if (s[l++] != s[r--]) return 0;
        }
        return 1;
    }
    
    void backtrack (vector<vector<string> >&vec, vector<string> temp, string s, int idx) {
        if (idx == s.size()) vec.push_back(temp);
        else {
            for (int i=idx; i<s.size(); i++) {
                if (isPalindrome(s, idx, i)) {
                    temp.push_back(s.substr(idx, i - idx + 1));
                    backtrack(vec, temp, s, i + 1);
                    temp.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> temp;
        backtrack(ans, temp, s, 0);
        return ans;
    }
};