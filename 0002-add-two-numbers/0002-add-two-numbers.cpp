/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void solve(ListNode  * l1 , ListNode* l2 , ListNode * curr , int & carry){
        if(!l1 && !l2) {
            if(carry){
                curr->next = new ListNode(carry);
            }
            return ;
        }
        int val = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;

        carry = val >= 10 ? 1 : 0;

        curr->next = new ListNode(val % 10);

        solve((l1 ? l1->next : l1) , (l2 ? l2->next : l2) , curr->next , carry);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * res = new ListNode(-1);
        ListNode* tail  =res;
        int carry = 0;
        solve(l1 , l2 , tail, carry);

        return res->next;
    }
};