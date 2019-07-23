class Solution {
public:
    
    vector<string> split(string &a, char c) {
        vector<string> ret;
        string cur;
        for (auto &x : a) {
            if (x == c) ret.push_back(cur), cur = "";
            else cur += x;
        }
        if (cur != "") ret.push_back(cur);
        return ret;
    }
    
    string reverseWords(string s) {
        s = std::regex_replace(s, std::regex("^ +| +$|( ) +"), "$1");
        vector<string> vec = split(s, ' ');
        reverse(vec.begin(), vec.end());
        string ans = "";
        for (size_t i=0; i<vec.size(); i++) {
            ans += vec[i];
            if (i != vec.size() - 1) ans += " ";
        }
        return ans;
    }
};