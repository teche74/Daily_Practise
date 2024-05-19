/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int level =0 ;

        stack<Node * >st,rem;

        st.push(root);

        while(st.size()){
            Node * frnt = st.top();
            st.pop();

            if(frnt->children.size()){
                for(auto t : frnt->children){
                    rem.push(t);
                }
            }

            if(st.empty()){
                while(!rem.empty()){
                    st.push(rem.top());
                    rem.pop();
                }
                level++;
            }
        }

        return level;
    }
};