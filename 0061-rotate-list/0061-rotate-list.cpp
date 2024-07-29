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
    int getlen(ListNode * root){
        int cnt = 0;
        

        while(root != nullptr){
            cnt++;
            root= root->next;
        }

        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        int len  = getlen(head);

        k %= len;

        if(k == 0 ) return head;

        ListNode * ptr = head;

        for(int i = 0; i < len- k -1 ; i++){
            ptr = ptr->next;
        } 

        ListNode * res = ptr->next;
        ptr->next = nullptr;

        ListNode * tail = res;

        while(tail->next){
            tail=tail->next;
        }

        tail->next =head;
        return res;


    }
};