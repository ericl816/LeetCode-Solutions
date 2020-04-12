class Solution {
public:
    string entityParser(string text) {
        string x[6] = {"&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"};
        string y[6] = {"\"", "\'", "&", ">", "<", "/"};
        string result = "";
        int l = text.size();
        for (int i = 0; i < l;) {
            bool matched = false;
            for (int j = 0; j < 6; j++) {
                int k = 0;
                for (k; k < x[j].size() && k < l; k++) {
                    if (x[j][k] != text[i + k]) break;
                }
                if (k == x[j].size()) {
                    matched = true;
                    result += y[j];
                    i += x[j].size();
                    break;
                }
            }
            if (!matched) {
                result += text[i++];
            }
        }
        return result;
    }
};