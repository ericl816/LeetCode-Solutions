class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty()) {
            return 0;
        }
        int maxx = 0;
        vector<int> freq(s.size(), 0);
        int l = 0, r = 0, len = 0;
        while (r < s.size()) {
            maxx = max(maxx, ++freq[s[r++] - 'A']);
            if (len - maxx < k) {
                ++len;
            } else {
                --freq[s[l++] - 'A'];
            }
        }
        return len;
    }
};
