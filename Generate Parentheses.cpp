class Solution {
public:
    
    void recur (vector<string> &ans, string &str, int l, int r) {
        if (l > r || l < 0 || r < 0) return;
        if (l == 0 && r == 0) {
            ans.push_back(str);
            return;
        }
        str.push_back('(');
        recur(ans, str, l - 1, r);
        str.pop_back();
        str.push_back(')');
        recur(ans, str, l, r - 1);
        str.pop_back();
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        recur(ans, s, n, n);
        return ans;
    }
};