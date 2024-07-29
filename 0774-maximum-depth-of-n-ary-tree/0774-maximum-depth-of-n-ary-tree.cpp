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
        int max_level = 0;

        if(!root) return max_level;

        queue<pair<Node*,int>> q;

        q.push(make_pair(root,1));

        while(!q.empty()){
            int size = q.size();

            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();

            max_level = max(max_level, level);

            for (auto child : node->children) {
                q.push(make_pair(child, level + 1));
            }
        }
        return max_level;
    }
};