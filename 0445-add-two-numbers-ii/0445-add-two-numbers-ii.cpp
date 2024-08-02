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
    ListNode * reverse(ListNode * head){
        ListNode * prev = nullptr , *curr =head, *temp = nullptr;

        while(curr != nullptr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
       ListNode * res  = new ListNode(-1);
       ListNode *tail = res;

       ListNode *l1 = reverse(list1);
       ListNode *l2 = reverse(list2);

       int x = 0 , y = 0 , carry = 0;

       while(l1 || l2 || carry){
            x = l1 != nullptr ? l1->val : 0;
            y = l2 != nullptr ? l2->val : 0;

            int sum = x+ y+ carry;

            carry = sum > 9 ? 1 : 0;
            tail->next= new ListNode(sum %10);
            tail =tail->next;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
       }

       res = res->next;
       return reverse(res);
    }
};