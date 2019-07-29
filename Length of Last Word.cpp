class Solution {
public:
    
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int n = 0, i = s.size() - 1;
        while (s[i] == ' ') i--;
        for (; i >= 0; i--, n++) {
            if (s[i] == ' ') return n;
        }
        return n;
    }
};