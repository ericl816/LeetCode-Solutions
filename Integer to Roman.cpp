class Solution {
public:
    string intToRoman(int num) {
        static const string roman[4][10]= { 
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"},
        };
        return roman[3][num / 1000 % 10] + roman[2][num / 100 % 10] + roman[1][num / 10 % 10] + roman[0][num % 10];
    }
};