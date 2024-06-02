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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return nullptr;

        ListNode * res = new ListNode(-1);
        ListNode * curr_res = res;
        ListNode * curr = head;

        while(curr){
            while(curr_res->next && curr->val > curr_res->next->val ) curr_res = curr_res->next;
            ListNode * temp = curr_res->next;
            curr_res->next = new ListNode(curr->val);
            curr_res->next->next  =temp;
            curr=curr->next;
            curr_res = res; 
        }

        return res->next;
    }
};