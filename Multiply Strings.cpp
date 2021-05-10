class Solution {
public:
    string multiply(string num1, string num2) {
    	string ans = "";
    	if (num1 == "0" || num2 == "0") {
    		return "0";
    	}
    	string sum(num1.size() + num2.size(), '0');
    	int a = num1.size(), b = num2.size();
    	for (int i=num1.size() - 1; i>=0; i--) {
    		int carry = 0;
    		for (int j=num2.size() - 1; j>=0; j--) {
    			int res = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[i] - '0') + carry;
    			sum[i + j + 1] = (res % 10) + '0';
    			carry = res / 10;
    		}
    		sum[i] += carry;
    	}
    	for (int i=0; i<sum.size(); i++) {
    		if (sum[i] != '0') {
    			return sum.substr(i);
    		}
    	}
    	return "0";
    }
};
