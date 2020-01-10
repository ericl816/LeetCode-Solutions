class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> vert, horiz, diag, antdiag;
        unordered_map<int, unordered_map<int, int> > dict;
        for (auto i : lamps) {
            dict[i[0]][i[1]]++;
            horiz[i[0]]++;
            vert[i[1]]++;
            diag[i[0] - i[1]]++;
            antdiag[i[0] + i[1]]++;
        }
        vector<int> ans;
        for (auto i : queries) {
            if (horiz[i[0]] || vert[i[1]] || diag[i[0] - i[1]] || antdiag[i[0] + i[1]]) ans.push_back(1);
            else ans.push_back(0);
            for (int j=-1; j<=1; j++) {
                for (int k=-1; k<=1; k++) {
                    int x = i[0] + j, y = i[1] + k;
                    if (dict[x][y]) {
                        dict[x][y] = 0;
                        horiz[x]--;
                        vert[y]--;a
                        diag[x - y]--;
                        antdiag[x + y]--;
                    }
                }
            }
        }
        return ans;
    }
};