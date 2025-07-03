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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;

        if(!root) return res;
        queue<vector<Node *>>q;
        q.push(vector<Node*>{root});

        while(q.size()){
            vector<Node *> front = q.front();q.pop();
            vector<int>temp;
            vector<Node *>next;

            for(auto t : front){
                temp.push_back(t->val);

                for(auto val : t->children){
                    next.push_back(val);
                }
            }

            if(!next.empty())
                q.push(next);
            res.push_back(temp);
        }

        return res;
    }
};