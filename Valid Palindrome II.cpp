class Solution {
public:
    
    bool valid (string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return 0;
        }
        return 1;
    }
    
    bool validPalindrome(string s) {
        if (valid(s, 0, s.size() - 1)) return 1;
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return valid(s, l + 1, r) || valid(s, l, r - 1);
            l++, r--;
        }
        return 1;
    }
};