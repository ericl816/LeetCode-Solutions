void rotateCCW (vector<vector<int> > &vec) {
	int N = vec.size();
	for (int i=0; i<N / 2; i++) {
		for (int j=i; j<N - i - 1; j++) {
			int temp = vec[i][j];
			vec[i][j] = vec[j][N - i - 1]; // Move from right to top
			vec[j][N - i - 1] = vec[N - i - 1][N - j - 1]; // Move from bottom to right
			vec[N - j - 1][i] = vec[N - i - 1][N - j - 1]; // Move from left to bottom
			vec[N - j - 1][i] = temp;
		}
	}
}

void rotateCW (vector<vector<int> > &vec) {
	int N = vec.size();
	for (int i=0; i<N / 2; i++) {
		for (int j=i; j<N - i - 1; j++) {
			int temp = vec[i][j];
			vec[i][j] = vec[N - j - 1][i]; // Move from left to top
			vec[N - j - 1][i] = vec[N - i - 1][N - j - 1]; // Move from bottom to left
			vec[N - i - 1][N - j - 1] = vec[j][N - i - 1]; // Move from right to bottom
			vec[j][N - i - 1] = temp;
		}
	}
}