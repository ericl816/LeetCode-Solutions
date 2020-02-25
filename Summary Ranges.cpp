class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        vector<string> ans;
        if (a.empty()) return ans;
        string s = "";
        for (int i=0; i<a.size() - 1; i++) {
            if (a[i] != a[i + 1] - 1) {
                if (s.empty()) {
                    ans.push_back(to_string(a[i]));
                }
                else {
                    s += "->";
                    s += to_string(a[i]);
                    ans.push_back(s);
                    s = "";
                }
            }
            else {
                if (s.empty()) {
                    s += to_string(a[i]);
                }
            }
        }
        if (s.empty()) {
            ans.push_back(to_string(a.back()));
        }
        else {
            ans.push_back(s + "->" + to_string(a.back()));
        }
        return ans;
    }
};