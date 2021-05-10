class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return 1;
        set<char> s;
        for (auto i : str2) s.insert(i);
        if (s.size() == 26) return 0;
        map<char, char> dict;
        for (size_t i=0; i<str1.size(); i++) {
            if (dict.find(str1[i]) == dict.end()) dict[str1[i]] = str2[i];
            else {
                if (dict[str1[i]] != str2[i]) return 0;
            }
        }
        return 1;
    }
};