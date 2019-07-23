class Solution {
public:
    int myAtoi(string str) {
        long long ans = 0;
        int sign = 1;
        for (size_t i=0; i<str.size();) {
            i = str.find_first_not_of(' ');
            if (i != string::npos) {
                if (str[i] == '-' || str[i] == '+') sign = (str[i++] == '+') ? 1 : -1;
                while (str[i] >= '0' && str[i] <= '9') {
                    ans = ans * 10 + (str[i++] - '0');
                    if (ans * sign >= INT_MAX) return INT_MAX;
                    if (ans * sign <= INT_MIN) return INT_MIN;                
                }
            }
            return ans * sign;
        }
        return 0;
    }
};