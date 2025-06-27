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
        queue<pair<Node *,int>>q;
        q.push({root,1});
        int level = 0;


        while(q.size()){
            auto front = q.front();q.pop();
            level = max(level , front.second);

            if(front.first->children.size()){
                for(auto node :front.first->children){
                    q.push({node, front.second+1});
                }
            }
        }

        return level;
    }
};