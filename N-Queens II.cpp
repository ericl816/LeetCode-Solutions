class Solution {
public:
    int totalNQueens(int n) {
        if (n == 1) {
            return 1;
        } else if (n >= 2 && n <= 3) {
            return 0;
        }
        int ans = 0;
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
    
    void backtrack(int col, int n, vector<vector<bool> > &board, int &ans) {
        if (col == n) {
            ++ans;
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
};