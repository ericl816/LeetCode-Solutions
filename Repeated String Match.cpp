class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string res = A;
        for (int i=1; i<=ceil(B.size() / A.size()) + 2; i++, res+=A) {
            if (res.find(B) != string::npos) return i;
        }
        return -1;
    }
};