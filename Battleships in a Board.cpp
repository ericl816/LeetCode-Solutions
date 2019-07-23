class Solution {
public:
    
    int N, M;
    int movex[4] = {0, 0, -1, 1};
    int movey[4] = {-1, 1, 0, 0};
    bool vis[210][210];
    
    void DFS (vector<vector<char>>& board, int x, int y) {
        if (x >= N || x < 0 || y >= M || y < 0 || vis[x][y] || board[x][y] == '.') return;
        vis[x][y] = 1;
        for (int i=0; i<4; i++) DFS(board, x + movex[i], y + movey[i]);
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        if (board.empty()) return 0;
        N = board.size(), M = board[0].size();
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (board[i][j] == 'X' && !vis[i][j]) {
                    ans++;
                    DFS(board, i, j);
                }
            }
        }
        return ans;
    }
};