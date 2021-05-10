class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> result, ret;
        for (int i = 1; i <= m; i++) {
            result.push_back(i);
        }
        for (int i = 0; i < queries.size(); i++) {
            for (int j = 0; j < result.size(); j++) {
                if (result[j] == queries[i]) {
                    ret.push_back(j);
                    for (int k = j; k > 0; k--) result[k] = result[k - 1];
                    result[0] = queries[i];
                    break;
                }
            }
        }
        return ret;
    }
};