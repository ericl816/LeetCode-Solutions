struct BIT {
private:
    vector<int> tree;
    
public:
    BIT (int N) : tree(N) { }
    
    void Update (int idx, int val) {
        for (; idx<tree.size(); idx += idx & -idx) tree[idx] += val;
    }
    
    int Query (int idx) {
        int sum = 0;
        for (; idx>0; idx -= idx & -idx) sum += tree[idx];
        return sum;
    }
};

class Solution {
    
public:
    
    // BIT solution
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = 0, ind = 0;
        set<long long> s;
        for (long long i : nums) {
            s.insert(i), s.insert(i * 2);
        }
        map<long long, int> comp;
        for (auto i : s) comp[i] = ++ind;
        BIT tree(s.size() + 10);
        for (int i=nums.size() - 1; i>=0; i--) {
            ans += tree.Query(comp[nums[i]] - 1);
            tree.Update(comp[2 * (long long) nums[i]], 1);
        }
        return ans;
    }

    void Check (int &cnt, vector<int> &nums, int lo, int mid, int hi) {
        int l = lo, r = mid + 1; // Use 2-pointers
        while (l <= mid && r <= hi) {
            if ((long long) nums[l] > 2 * (long long) nums[r]) {
                cnt += mid - l + 1;
                r++;
            }
            else l++;
        }
        sort(nums.begin() + lo, nums.begin() + hi + 1);
        return;
    }

    void mergeSort (int &cnt, vector<int> &nums, int lo, int hi) {
        if (lo == hi) return;
        int mid = (lo + hi) >> 1;
        mergeSort(cnt, nums, lo, mid);
        mergeSort(cnt, nums, mid + 1, hi);
        Check(cnt, nums, lo, mid, hi);
        return;
    }

    // Merge Sort solution (100% more memory efficient than BIT solution even though both have O(N) space complexity)
    int reversePairs1 (vector<int> &nums) {
        if (nums.empty()) return 0;
        int ans = 0;
        mergeSort(ans, nums, 0, nums.size() - 1);
        return ans;
    }
};

