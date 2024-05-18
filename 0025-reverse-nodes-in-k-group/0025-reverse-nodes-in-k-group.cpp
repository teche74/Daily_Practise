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
        ListNode* prev = nullptr, *curr = head,* temp = nullptr;
        int count =k;

        ListNode * check = head;

        for(int i =0 ;i < k;i++){
            if(!check) return head;
            check=check->next;
        }

        while(curr != nullptr && count){
            temp = curr->next;
            curr->next  =prev;
            prev =curr;
            curr=temp;
            count--;
        }

        if(temp){
            head->next = reverseKGroup(temp,k); 
        }

        return prev;
    }
};