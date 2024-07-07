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
    int count  = 0;
    ListNode * reverse(ListNode * head){
        ListNode * prev = nullptr, * curr= head, * temp = nullptr;

        while (curr !=  nullptr){
            count++;
            temp = curr->next;
            curr->next  =prev;
            prev =curr;
            curr=temp;
        }

        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode * slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *rev = reverse(slow);
        ListNode *temp = head;
        int res = 0;

        while(rev){
            res = max(res, temp->val + rev->val);
            temp = temp->next;
            rev = rev->next;
        }

        return res;
    }
};