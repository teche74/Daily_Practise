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
        ListNode * ptr = head;
        bool valid = true;

        for(int i =0 ; i < k ; i++){
            if(!ptr){
                valid = false;
                break;
            }
            ptr = ptr->next;
        }

        if(!valid) return head;

        ListNode * curr = head, * prev = nullptr , * temp = nullptr;
        int turn = k;
        
        while(curr && turn){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            turn--;
        }

        if(temp){
            head->next =reverseKGroup(temp , k);
        }

        return prev;
    }
};