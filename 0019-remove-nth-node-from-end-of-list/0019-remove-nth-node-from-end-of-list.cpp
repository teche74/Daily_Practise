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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode temp(-1);

        temp.next = head;

        ListNode * slow = &temp, * fast = &temp ;

        for(int  i =0; i <= n; i++){
            fast=fast->next;
        }

        while(fast!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }

        ListNode * t = slow->next;
        slow->next = t->next;
        delete t;
        return temp.next;
    }
};