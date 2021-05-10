class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, l = 0;
        map<char, int> dict;
        for (int i=0; i<s.size(); i++) {
            if (dict.count(s[i])) {
                l = max(l, dict[s[i]]);
            }
            ans = max(ans, i - l + 1);
            dict[s[i]] = i + 1;
        }
        return ans;
    }
};