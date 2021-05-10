class Solution {
public:
	// Time Complexity: O(N * M^2)
	bool isRectangle (const vector<vector<int> > &matrix) {
		if (matrix.empty()) return 0;
		int rows = matrix.size();
		int cols = matrix[0].size();
		unordered_map<int, unordered_set<int> > dict;
		for (int i=0; i<rows; i++) {
			for (int j=0; j<cols - 1; j++) {
				for (int k=j + 1; k<cols; k++) {
					if (matrix[i][j] == 1 && matrix[i][k] == 1) {
						if (dict.find(j) != dict.end() && dict[j].find(k) != dict[j].end()) return 1;
						dict[j].insert(k);
					}
				}
			}
		}
		return 0;
	}
};