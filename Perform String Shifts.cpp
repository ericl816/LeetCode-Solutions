class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        if (shift.empty()) return s;
        int res = 0;
        for (auto i : shift) {
            if (!i[0]) res -= i[1];
            else res += i[1];
        }
        if (res < 0) {
            res *= -1;
            string ss = s.substr(0, res % s.size());
            return s.substr(res % s.size()) + ss;
        }
        string ss = s.substr(s.size() - (res % s.size()));
        return ss + s.substr(0, s.size() - (res % s.size()));
    }
};