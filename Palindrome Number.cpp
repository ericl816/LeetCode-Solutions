class Solution {
public:
    bool isPalindrome (int x) {
        string s = to_string(x);
        if (s.length() == 1) return 1;
        return (s == string(s.rbegin(), s.rend()));
    }
};