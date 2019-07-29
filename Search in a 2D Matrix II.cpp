class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size(), idx = -1;
        for (int r=0, c=m - 1; r<n && c>=0;) {
            if (matrix[r][c] == target) return 1;
            else if (matrix[r][c] > target) c--;
            else r++;
        }
        return ~idx;
    }
};