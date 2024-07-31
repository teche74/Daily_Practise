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
        if(!root) return {};
        queue<Node *>q;

        q.push(root);

        while(!q.empty()){
            long long size =q.size();

            vector<int>temp;

            for(long long i = 0; i < size ; i++){
                Node * front= q.front();
                q.pop();
                temp.emplace_back(front->val);
                if(!front->children.empty()){
                    for(auto t : front->children){
                        q.push(t);
                    }
                }
            }
            res.emplace_back(temp);
        }
        return res;
    }
};