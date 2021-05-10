class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> grid[3][3];
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                char ch = board[i][j];
                if (ch != '.') {
                    if (rows[i].count(ch) || cols[j].count(ch) || grid[i / 3][j / 3].count(ch)) {
                        return 0;
                    }
                    rows[i].insert(ch);
                    cols[j].insert(ch);
                    grid[i / 3][j / 3].insert(ch);
                }
            }
        }
        return 1;
    }
};
