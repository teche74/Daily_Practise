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
        unordered_map<int,int>seen;

        for(int x : nums){
            seen[x]++;
        }

        ListNode * res = new ListNode(-1);
        ListNode * tail = res , * trav = head;

        while(trav){
            if(seen.find(trav->val) == seen.end()){
                tail->next = new ListNode(trav->val);
                tail = tail->next;
            }
            trav = trav->next;
        }

        return res->next;
    }
};