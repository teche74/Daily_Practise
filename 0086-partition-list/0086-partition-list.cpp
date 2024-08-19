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
    ListNode* partition(ListNode* head, int x) {
        ListNode * prev = new ListNode(-1);
        ListNode * p_tail = prev;

        ListNode * fur = new ListNode(-1);
        ListNode * f_tail = fur;

        while(head){
            if(head->val < x){
                p_tail->next = head;
                p_tail= p_tail->next;
            }
            else{
                f_tail->next = head;
                f_tail= f_tail->next;
            }
            head=head->next;
        }

        p_tail->next = fur->next;
        f_tail->next = nullptr;
        return prev->next;
    }
};