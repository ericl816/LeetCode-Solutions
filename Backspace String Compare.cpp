class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s = "", t = "";
        for (int i=0; i<S.size(); i++) {
            if (S[i] == '#') {
                if (s.empty()) {
                    continue;
                }
                s.pop_back();
            }
            else {
                s.push_back(S[i]);
            }
        }
        for (int i=0; i<T.size(); i++) {
            if (T[i] == '#') {
                if (t.empty()) {
                    continue;
                }
                t.pop_back();
            }
            else {
                t.push_back(T[i]);
            }
        }
        if (s.size() != t.size()) return 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] != t[i]) return 0;
        }
        return 1;
    }
};