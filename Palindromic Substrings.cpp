class Solution {
public:
    bool isPalindrome (string s) {
        if (s.length() == 1) return 1;
        return (s == string(s.rbegin(), s.rend()));
    }
    
    int countSubstrings(string s) {
        int ans = 0;
        for (int i=0; i<s.length(); i++) {
            for (int j=1; j<=s.length() - i; j++) {
                string next = s.substr(i, j);
                if (isPalindrome(next)) ans++;
            }
        }
        return ans;
    }
};