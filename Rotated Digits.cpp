class Solution {
public:
    int rotatedDigits(int N) {
        map<char, char> dict;
        dict['2'] = '5';
        dict['5'] = '2';
        dict['6'] = '9';
        dict['9'] = '6';
        int ans = 0;
        for (int i=1; i<=N; i++) {
            string s = to_string(i), ss = "";
            bool flag = 1;
            if (s.find('3') != string::npos || s.find('4') != string::npos || s.find('7') != string::npos) continue;
            for (int j=0; j<s.size(); j++) {
                if (dict.count(s[j])) ss += dict[s[j]];
                else ss += s[j];
            }
            ans += s != ss;
        }
        return ans;
    }
};