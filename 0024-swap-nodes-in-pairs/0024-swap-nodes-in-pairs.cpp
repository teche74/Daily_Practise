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
    ListNode* swapPairs(ListNode* head) {
        int count=2;
        ListNode*curr=head;
        ListNode*temp=NULL,*forward=NULL;
        while(curr&&count)
        {
            forward=curr->next;
            curr->next=temp;
            temp=curr;
            curr=forward;
            count--;
        }
        if(forward)
        {
            head->next=swapPairs(forward);
        }
        return temp;
    }
};