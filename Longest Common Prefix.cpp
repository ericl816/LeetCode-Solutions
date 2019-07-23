class Solution {
public:
    
    string common (string a, string b) {
        string res = "";
        for (size_t i=0, j=0; i<a.size() && j<b.size(); i++, j++) {
            if (a[i] != b[j]) break;
            res.push_back(a[i]);
        }
        return res;
    }
    
    string solve (vector<string> &strs, int l, int r) {
        if (l == r) return strs[l];
        if (l <= r) {
            int mid = (l + r) >> 1;
            return common(solve(strs, l, mid), solve(strs, mid + 1, r));
        }
        return "";
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        return solve(strs, 0, strs.size() - 1);
    }
};