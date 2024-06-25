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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * res = new ListNode(-1);
        ListNode * tail = res;
        ListNode * temp = head;

        unordered_map<int,int>map;

        while(temp){
            map[temp->val]++;
            temp=temp->next;
        }
        
        temp=head;

        while(temp){
            if(map[temp->val] == 1){
                tail->next = new ListNode(temp->val);
                tail=tail->next;
            }
            temp = temp->next;
        }

        return res->next;
    }
};