/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node * , Node *>map;

        Node * trav = head;

        while(trav){
            map[trav] = new Node(trav->val);
            trav = trav->next;
        }

        trav = head;

        while(trav){
            map[trav]->next = map[trav->next];
            map[trav]->random = map[trav->random];
            trav=trav->next;
        }

        return map[head];
    }
};