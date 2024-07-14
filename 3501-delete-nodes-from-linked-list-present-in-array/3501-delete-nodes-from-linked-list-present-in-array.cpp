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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode * temp = new ListNode(-1);
        ListNode * tail = temp;

        int map[1000000];

        memset(map, 0, sizeof(map));

        for(int x : nums){
            map[x]++;
        }

        while(head != nullptr){
            if(map[head->val] == 0){
                tail->next = new ListNode(head->val);
                tail=tail->next;
            }
            head=head->next;
        }

        return temp->next;
    }
};