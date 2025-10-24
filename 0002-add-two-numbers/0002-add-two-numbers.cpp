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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * res = new ListNode(-1);
        ListNode * tail = res;

        int val1 = 0 , val2 = 0 , carry = 0 ;

        while(l1 || l2 || carry){
            val1 = (l1 ? l1->val : 0);
            val2 = (l2 ? l2->val : 0);

            int total = val1 + val2 + carry;

            carry = total > 9 ? 1 : 0;

            tail->next = new ListNode(total % 10);
            tail = tail->next;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2; 
        }

        return res->next;
    }
};