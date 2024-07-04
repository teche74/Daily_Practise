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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * res = new ListNode(-1);
        ListNode * tail = res;
        ListNode * trav = head->next;

        int sum = 0;

        while(trav){
            sum += trav->val;
            if(trav->val == 0){
                tail->next = new ListNode(sum);
                tail=tail->next;
                sum= 0;
            }
            trav=trav->next;
        }

        return res->next;
    }
};