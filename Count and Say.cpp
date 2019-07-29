class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1);
        int cnt = 1;
        string s = "";
        for (size_t i=1; i<prev.size(); i++) {
            if (prev[i] == prev[i - 1]) ++cnt;
            else {
                s += to_string(cnt);
                s += prev[i - 1];
                cnt = 1;
            }
        }
        s += to_string(cnt);
        s += prev[prev.size() - 1];
        return s;
    }
};