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
    void solve(Node * root, vector<int> & res){
        if(root){
            if(!root->children.empty()){
                for(auto t : root->children){
                    solve(t,res);
                    // res.emplace_back(t->val);
                }
            }
            res.emplace_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int>res;

        solve(root,res);

        return  res;
    }
};