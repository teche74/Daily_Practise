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
    ListNode * reverse(ListNode * head, int k = 0)
    {
        ListNode * prev = nullptr , * curr = head, * temp = nullptr;

        if(k == 0){
            while(curr!=nullptr){
                temp = curr->next;
                curr->next  =prev;
                prev = curr;
                curr=temp;
            }
            return prev;
        }
        else{
            int t = k;
            while(curr!=nullptr && t){
                temp = curr->next;
                curr->next  =prev;
                prev = curr;
                curr=temp;
                t--;
            }
            return prev;
        }
    }

    int len(ListNode * head){
        int cnt{0};
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        
        int size = len(head);
        if (size == 0) return head;

        k %= size;
        if (k == 0) return head;
        
        ListNode* oldTail = head;
        for (int i = 1; i < size; i++) {
            oldTail = oldTail->next;
        }
        
        oldTail->next = head;

        ListNode* newTail = head;
        for (int i = 0; i < size - k - 1; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;

        newTail->next = nullptr;

        return newHead;
    }
};