class Solution {
public:
    double myPow(double x, int n) {
    	if (!n) {
    		return 1;
    	}
    	double res = myPow(x, n / 2);
    	if (n < 0) {
    		x = 1 / x;
    	}
    	if (n & 1) {
    		return res * res * x;
    	}
    	return res * res;
    }
};