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
        ListNode * tail  =res;

        int val1 = 0 , val2 = 0 , carry = 0;

        while(l1 || l2 || carry){
            val1 = l1 != nullptr ? l1->val : 0;
            val2 = l2 != nullptr ? l2->val : 0;

            int sum = val1 + val2 + carry;
            
            carry = (sum > 9) ? 1 : 0;
            sum = sum > 9 ? sum % 10 : sum;

            tail->next  = new ListNode(sum);
            tail=tail->next;

            l1 = l1 != nullptr ?  l1->next : l1;
            l2 = l2 != nullptr ?  l2->next : l2;
        }

        return res->next;
    }
};