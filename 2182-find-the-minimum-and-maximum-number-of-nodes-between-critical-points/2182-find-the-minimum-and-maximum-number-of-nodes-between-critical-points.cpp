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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int index  = 1; 

        ListNode * trav = head;
        ListNode * prev = nullptr, * curr = nullptr , *temp = nullptr;

        vector<int>ind;

        while(trav!= nullptr){
            prev = curr ;
            curr = trav;
            temp = trav->next != nullptr ? trav->next : nullptr;

            // cout<<(prev != nullptr ?prev->val : 0)<<" "<<(curr != nullptr ? curr->val : 0)<<" "<<(temp!= nullptr ? temp->val : 0 )<<endl; 

            if(prev != nullptr && temp!=nullptr){
                if( (curr->val < temp->val && curr->val < prev->val) ||  (curr->val > prev->val && curr->val > temp->val) ){
                    ind.emplace_back(index);
                    // cout<<index<<" ";
                }
            } 
            index++;
            trav = trav->next;
        }

        if (ind.size() < 2) {
            return {-1, -1};
        }

        int mini = INT_MAX;
        for (int i = 1; i < ind.size(); ++i) {
            mini = min(mini, ind[i] - ind[i - 1]);
        }

        int maxi = ind.back() - ind.front();
        return {mini, maxi};

    }
};