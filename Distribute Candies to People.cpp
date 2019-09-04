class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        if (!candies) return vector<int>{};
        vector<int> ans(num_people);
        int num = 1, sum = 0;
        while (sum <= candies) {
            for (int i=0; i<num_people; i++) {
                if (sum + num > candies) {
                    ans[i] += candies - sum;
                    goto outer;
                }
                else {
                    ans[i] += num;
                    sum += num;
                    num++;
                }
            }
        }
        outer:;
        return ans;
    }
};