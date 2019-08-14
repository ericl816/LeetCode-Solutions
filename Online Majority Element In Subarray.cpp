class MajorityChecker {
public:
    
    int N;
    vector<int> vec, large;
    int cheese[20010][510];
    int freq[20010];
    
    MajorityChecker(vector<int>& arr) {
        vec.assign(arr.size(), 0);
        N = arr.size();
        for (size_t i=0; i<arr.size(); i++) vec[i] = arr[i];
        for (auto i : vec) freq[i]++;
        for (int i=1; i<=20000; i++) {
            if (freq[i] > 100) large.push_back(i);
        }
        for (size_t i=0; i<large.size(); i++) {
            for (size_t j=0; j<vec.size(); j++) {
                cheese[j + 1][i] = cheese[j][i];
                if (large[i] == vec[j]) cheese[j + 1][i]++;
            }
        }
        memset(freq, 0, sizeof(freq));
    }
    
    int query(int left, int right, int threshold) {
        int ans = -1;
        if (threshold > 100) {
            for (size_t i=0; i<large.size(); i++) {
                if (cheese[right + 1][i] - cheese[left][i] >= threshold) ans = large[i];
            }
        }
        else {
            for (int i=left; i<=right; i++) {
                freq[vec[i]]++;
                if (freq[vec[i]] >= threshold) ans = vec[i];
            }
            memset(freq, 0, sizeof(freq));
        }
        return ans;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */