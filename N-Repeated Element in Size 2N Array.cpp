class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> s;
        for (auto i : A) {
            if (s.count(i)) return i;
            s.insert(i);
        }
        return 0;
    }
};