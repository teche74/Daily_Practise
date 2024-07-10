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

        ListNode * fast = &temp;

        for(int i =0 ; i <= n ; i++){
            fast=fast->next;
        }

        ListNode * slow = &temp;

        while(fast != nullptr){
            fast = fast->next;
            slow=slow->next;
        } 

        ListNode * ptr = slow->next;
        slow->next = ptr->next;
        delete ptr;

        return temp.next;
    }
};