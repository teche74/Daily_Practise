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
        int swap = 2;

        ListNode * prev = nullptr ,  *curr = head,  *temp = nullptr;

        while(curr && swap){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            swap--;
        }

        if(temp){
            head->next = swapPairs(temp);
        }

        return prev;
    }
};