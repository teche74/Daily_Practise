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
        ListNode * temp = new ListNode(-1);
        ListNode * tail = temp;

        int x = 0 , y = 0 , carry= 0;

        while(l1 || l2 || carry){
            x = l1 != nullptr ? l1->val : 0;
            y = l2 != nullptr ? l2->val : 0;

            int sum = x+ y + carry;

            carry = sum > 9 ? 1 : 0;

            tail->next = new ListNode(sum %10);
            tail=tail->next;

            l1 = l1 != nullptr ? l1->next : l1 ;
            l2 = l2 != nullptr ? l2->next : l2 ;  
        }

        return temp->next;
    }
};