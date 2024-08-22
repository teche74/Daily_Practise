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
    unordered_map<int, ListNode *>map;
    Solution(ListNode* head) {
        int index = 0;

        ListNode * trav = head;

        while(trav){
            map[index++] = trav;
            trav=trav->next;
        }
    }
    
    int getRandom() {
        int size = map.size();
        return map[rand() % size]->val; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */