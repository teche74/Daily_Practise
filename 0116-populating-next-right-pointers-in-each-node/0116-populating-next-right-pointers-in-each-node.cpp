/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node * >q;

        if(!root) return nullptr;

        q.push(root);

        while(q.size()){
            int size = q.size();
            Node * prev = nullptr;

            while(size--){
                Node *front =q.front();q.pop();

                if(prev){
                    prev->next = front;
                }
                prev = front;

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);

            }
            prev->next = nullptr;
        } 

        return root;
    }
};