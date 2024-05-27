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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=k;
        ListNode* curr=head,*prev=NULL,*forward=NULL;
        ListNode*temp=curr;
        for(int i=0;i<k;i++)
        {
            if(!temp)
            {
                return head;
            }
            temp=temp->next;
        }
        while(curr&&count)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count--;
        }
        if(forward)
        {
            head->next=reverseKGroup(forward,k);
        }
        return prev;
    }
};