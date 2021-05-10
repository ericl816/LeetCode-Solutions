class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<string> s;
        for (auto i : A) {
            string odd = "", even = "";
            for (size_t j=0; j<i.size(); j++) {
                if (j & 1) odd += i[j];
                else even += i[j];
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            s.insert(odd + even);
        }
        return s.size();
    }
};