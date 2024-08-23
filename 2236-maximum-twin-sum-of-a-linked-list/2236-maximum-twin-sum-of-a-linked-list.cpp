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
    int pairSum(ListNode* head) {
        stack<int>st;
        ListNode * trav =head;

        while(trav){
            st.push(trav->val);
            trav= trav->next;
        }

        trav =head;
        int res = 0;

        while(st.size()){
            res = max(res, st.top() + trav->val);
            st.pop();
            trav=trav->next;
        }

        return res;
    }
};