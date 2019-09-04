/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<ListNode*> vec;
        for (ListNode *res=head; res!=NULL; res=res->next) vec.push_back(res);
        for (int i=0; i<(int) vec.size(); i++) {
            int sum = 0;
            for (int j=i + 1; j<=(int) vec.size(); j++) {
                sum += vec[j - 1]->val;
                if (sum == 0) {
                    vec.erase(vec.begin() + i, vec.begin() + j);
                    j = i;
                }
            }
        }
        ListNode *ans = NULL;
        for (int i=(int) vec.size() - 1; i>=0; i--) {
            // if (i < vec.size() - 1) cout << vec[i]->next->val << " " << vec[i]->val << endl;
            vec[i]->next = ans;
            ans = vec[i];
        }
        return ans;
    }
};