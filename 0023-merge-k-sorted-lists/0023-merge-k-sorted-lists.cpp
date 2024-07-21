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
    ListNode * merge(ListNode * l1, ListNode * l2){
        ListNode *temp = new ListNode(-1);
        ListNode* tail = temp;

        while(l1 && l2){
            if(l1->val <= l2->val){
                tail->next =l1;
                l1=l1->next;
            }
            else{
                tail->next =l2;
                l2=l2->next;
            }
            tail=tail->next;
        }

        tail->next = l1 ? l1 : l2;

        return temp->next;
    }
    ListNode *solve(vector<ListNode*>list , int low , int high ){
        if(low == high) return list[low];
        if(low == high - 1) return merge(list[low], list[high]);

        int mid = low + (high - low)/2;

        ListNode * left = solve(list, low, mid);
        ListNode * right = solve(list, mid+1, high);

        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return solve(lists,0,lists.size()-1);
    }
};