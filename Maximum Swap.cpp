class Solution {
public:
    int maximumSwap(int num) {
        if (!num) return 0;
        string s = to_string(num);
        for (int i=0; i<s.size(); i++) {
            int idx = i;
            for (int j=i + 1; j<s.size(); j++) {
                if (s[idx] <= s[j]) {
                    idx = j;
                }
            }
            if (s[idx] != s[i]) {
                swap(s[idx], s[i]);
                break;
            }
        }
        int ans = 0;
        for (auto i : s) {
            ans = ans * 10 + i - '0';
        }
        return ans;
    }
};