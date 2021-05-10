/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> mat = binaryMatrix.dimensions();
        int r = mat[0], c = mat[1];
        if (!r || !c) return -1;
        int ans = -1;
        for (int i=0, j=c - 1; i<r && j>=0;) {
            if (binaryMatrix.get(i, j) == 1) {
                ans = j;
                j--;
            } else {
                i++;
            }
        }
        return ans;
    }
};