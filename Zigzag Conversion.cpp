class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> res(numRows + 1);
        int idx = 0;
        int dir = -1;
        for (size_t i=0; i<s.size(); i++) {
            if (i % (numRows - 1) == 0) dir *= -1;
            res[idx].push_back(s[i]);
            idx += dir;
        }
        string ret = "";
        for (auto s : res) ret += s;
        return ret;
    }
};