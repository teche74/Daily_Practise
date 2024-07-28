/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;

        Node * curr = nullptr;
        Node * tail = nullptr;
        stack<Node*> st;

        st.push(head);

        while(!st.empty()){
            Node * front = st.top();
            st.pop();

            if(front->next != nullptr){
                st.push(front->next);
            }
            
            if(front->child != nullptr){
                st.push(front->child);
                front->child = nullptr;
            }
            
            if (curr == nullptr) {
                curr = tail = front;
            } else {
                tail->next = front;
                front->prev = tail;
                tail = front;
            }
        }

        return head;
    }
};