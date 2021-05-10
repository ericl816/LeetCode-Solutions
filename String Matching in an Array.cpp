class kmp {
  public:
    static vector<int> pmt_of (string p) {
      vector<int> pmt = { -1 };
      for (int i = 0, j = -1; i < p.size(); ) {
        if (j == -1 || p[i] == p[j]) {
          ++i, pmt.push_back(++j);
        }
        else {
          j = pmt[j];
        }
      }
      return pmt;
    }

    static int first_of (string s, string p) {
      vector<int> pmt = pmt_of(p);
      int i = 0, j = 0;
      while (i < s.size() && j < (int) p.size()) {
        if (j == -1 || s[i] == p[j]) {
          ++i, ++j;
        }
        else {
          j = pmt[j];
        }
      }
      return j == (int) p.size() ? i - j : -1;
    }
};

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        for (int i = 0; i < words.size(); i++) {
            bool valid = false;
            for (int j = 0; j < words.size(); j++) {
                if (j != i) {
                    if (kmp::first_of(words[j], words[i]) != -1) {
                        valid = true;
                        break;
                    }   
                }
            }
            if (valid) {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};