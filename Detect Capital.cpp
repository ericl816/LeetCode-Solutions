class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag1 = 1, flag2 = 1, flag3 = 1;
        for (char i : word) {
            flag1 &= isupper(i) ? 1 : 0;
            flag2 &= islower(i) ? 1 : 0;
        }
        for (size_t i=1; i<word.size(); i++) flag3 &= islower(word[i]) ? 1 : 0;
        flag3 &= isupper(word[0]) ? 1 : 0;
        return flag1 || flag2 || flag3;
    }
};