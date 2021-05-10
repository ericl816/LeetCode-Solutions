class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        map<int, int> freq;
        for (int i=0; i<1000; i++) freq[i] = 0;
        for (auto i : A) freq[i]++;
        for (int i=1000; i>=0; i--) {
            if (freq[i] == 1) return i;
        }
        return -1;
    }
};