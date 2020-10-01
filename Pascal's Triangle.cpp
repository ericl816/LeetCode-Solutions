class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans(0, vector<int>(0, numRows));
        if (!numRows) return ans;
        ans.push_back(vector<int>{1});
        numRows--;
        while (numRows--) {
            vector<int> temp = ans.size() ? ans.back() : vector<int>();
            vector<int> temp1;
            temp1.push_back(1);
            int len = temp.size();
            for (int i=0; i<len - 1; i++) {
                temp1.push_back(temp[i] + temp[i + 1]);
            }
            temp1.push_back(1);
            ans.push_back(temp1);
        }
        return ans;
    }
};