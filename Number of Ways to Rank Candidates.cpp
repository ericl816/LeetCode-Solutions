class Solution {
public:

	// O(N^2) time complexity
	// Remark: Isn't the solution just N! ?
    int numRankings(int N) {
    	if (!N) return 0;
    	int base[N + 1];
    	base[1] = 1;
    	for (int i=2; i<=N; i++) {
    		int temp[N + 1];
    		for (int j=1; j<N; j++) {
    			temp[j + 1] += base[j] * (j + 1);
    			temp[j] += base[j] * j;
    		}
    		base = temp;
    	}
    	int sum = 0;
    	for (int i=1; i<=N; i++) sum += base[i];
    	return sum;
    }
};