class Solution {
public:
    
    vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
    vector<string> boardd = {"afkpuz", "bglqv", "chmrw", "dinsx", "ejoty"};
        
    int conv1 (char ch) {
        for (int i=0; i<6; i++) {
            string s = board[i];
            size_t ind = s.find(ch);
            if (ind != string::npos) return i;
        }
        return -1;
    }
    
    int conv2 (char ch) {
        for (int i=0; i<5; i++) {
            string s = boardd[i];
            size_t ind = s.find(ch);
            if (ind != string::npos) return i;
        }
        return -1;
    }
    
    string alphabetBoardPath(string target) {
        string ans = "";
        int currx = 0, curry = 0;
        for (size_t i=0; i<target.size(); i++) {
            int nextx = conv1(target[i]), nexty = conv2(target[i]);
            if (target[i] != 'z') {
                if (nextx > currx) {
                    for (int j=0; j<abs(nextx - currx); j++) ans += "D";
                }
                else {
                    for (int j=0; j<abs(nextx - currx); j++) ans += "U";
                }
                if (nexty > curry) {
                    for (int j=0; j<abs(nexty - curry); j++) ans += "R";
                }
                else {
                    for (int j=0; j<abs(nexty - curry); j++) ans += "L";
                }
                ans += "!";
            }
            else {
                for (int j=0; j<abs(nexty - curry); j++) ans += "L";
                for (int j=0; j<abs(nextx - currx); j++) ans += "D";
                ans += "!";
            }
            currx = nextx, curry = nexty;
        }
        return ans;
    }
};