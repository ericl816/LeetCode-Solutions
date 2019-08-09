class Solution {
public:
    
    bool valid (char ch) {
        return isalpha(ch) || isdigit(ch);
    }
    
    bool isPalindrome(string s) {
        if (s.empty()) return 1;
        int lo = 0, hi = s.size() - 1;
        bool flag = 1;
        while (lo < hi) {
            char l = s[lo], r = s[hi];
            if (valid(l)) {
                if (valid(r)) {
                    flag &= (tolower(l) == tolower(r));
                    lo++, hi--;
                }
                else hi--;
            }
            else lo++;
        }
        return flag;
    }
};