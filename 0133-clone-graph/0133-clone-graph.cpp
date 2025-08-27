/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*>link;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(link.find(node) != link.end()) return link[node];

        Node * new_node = new Node(node->val);
        link[node] = new_node;

        for(auto neigh : node->neighbors){
            new_node->neighbors.push_back(cloneGraph(neigh));
        }
        return new_node;
    }
};