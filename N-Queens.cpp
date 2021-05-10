class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        if (n == 1) {
            vector<string> vec;
            vec.push_back("Q");
            ans.push_back(vec);
            return ans;
        } else if (n >= 2 && n <= 3) {
            return ans;
        }
        vector<vector<bool> > board(n, vector<bool>(n, 0));
        backtrack(0, n, board, ans);
        return ans;
    }
    
    bool isSafe(int row, int col, int n, vector<vector<bool> > &board) {
        for (int i=0; i<col; i++) {
            if (board[row][i]) {
                return 0;
            }
        }
        for (int i=row, j=col; i>=0 && j>=0; i--, j--) {
            if (board[i][j]) {
                return 0;
            }
        }
        for (int i=row, j=col; i<n && j>=0; i++, j--) {
            if (board[i][j]) {
                return 0;
            }
        }
        return 1;
    }
    
    void backtrack(int col, int n, vector<vector<bool> > &board, vector<vector<string> > &ans) {
        if (col == n) {
            addBoardConfig(n, board, ans);
            return;
        }
        for (int i=0; i<n; i++) {
            if (isSafe(i, col, n, board)) {
                board[i][col] = 1;
                backtrack(col + 1, n, board, ans);
                board[i][col] = 0;
            }
        }
    }
    
    void addBoardConfig(int n, vector<vector<bool> > &board, vector<vector<string> > &ans) {
        vector<string> vec;
        for (int i=0; i<n; i++) {
            string s = "";
            for (int j=0; j<n; j++) {
                if (board[i][j]) {
                    s += "Q";
                } else {
                    s += ".";
                }
            }
            vec.push_back(s);
        }
        ans.push_back(vec);
    }
    
};