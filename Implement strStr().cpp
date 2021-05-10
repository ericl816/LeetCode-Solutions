class Solution {
public:
    inline void KMP_Preprocess (int T[], string s, string t) {
        T[0] = -1;
        for (int i=0, j=-1; i<t.size(); i++, j++, T[i] = j) {
            while (j >= 0 && t[i] != t[j]) j = T[j];
        }
    }

    inline int KMP (int T[], string s, string t) {
        for (int i=0, j=0; i<s.size(); i++, j++) {
            while (j >= 0 && s[i] != t[j]) j = T[j];
            if (j == t.size() - 1) return abs(i - j);
        }
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        if ((haystack.empty() && needle.empty()) || needle.empty()) return 0;
        if (haystack.empty() || haystack.size() < needle.size()) return -1;
        int T[haystack.size() + 1];
        KMP_Preprocess(T, haystack, needle);
        return KMP(T, haystack, needle);
    }
};