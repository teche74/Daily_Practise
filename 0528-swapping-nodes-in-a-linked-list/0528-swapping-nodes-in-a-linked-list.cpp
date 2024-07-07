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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * temp = head;

        for(int i = 1; i <= k ;i++){
            temp = temp->next;
        }

        ListNode * tar1 = head; 

        while(temp != nullptr){
            temp = temp->next;
            tar1=tar1->next;
        }

        ListNode * tar2 = head;

        for(int i=1; i< k; i++){
            tar2 = tar2->next;
        }

        swap(tar1->val,tar2->val);

        return head;
    }
};