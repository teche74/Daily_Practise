/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void inord(TreeNode* root, vector<int>& inorder) {
        if (!root) return;
        inord(root->left, inorder);
        inorder.push_back(root->val);
        inord(root->right, inorder);
    }

    void pre(TreeNode* root, vector<int>& preorder) {
        if (!root) return;
        preorder.push_back(root->val);
        pre(root->left, preorder);
        pre(root->right, preorder);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> inorder, preorder;
        inord(root, inorder);
        pre(root, preorder);

        string res = "";

        for (auto t : inorder) {
            res += to_string(t) + '-';
        }
        res += '|';

        for (auto t : preorder) {
            res += to_string(t) + '-';
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int>inorder ,preorder;
        bool in_first= true; 
        int prev = 0;

        for(int i = 0 ;i <data.size() ; i++){
            if(data[i] == '|'){
                in_first = false;
                prev = i + 1;
                continue;
            }
            if(data[i] == '-'){
                int val = stoi(data.substr(prev, i - prev));
                prev = i+1;
                if(in_first){
                    inorder.emplace_back(val);
                }
                else{
                    preorder.emplace_back(val);
                }
            }
        }

        unordered_map<int,int>map;
        for(int i = 0; i < inorder.size() ; i++){
            map[inorder[i]]= i;
        }
        int index = 0;
        return buildTree(preorder, inorder, 0, inorder.size() - 1, index, map);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end, int& index, unordered_map<int, int>& map) {
        if (start > end) return nullptr;

        int val = preorder[index++];
        TreeNode* node = new TreeNode(val);
        int pos = map[val];

        node->left = buildTree(preorder, inorder, start, pos - 1, index, map);
        node->right = buildTree(preorder, inorder, pos + 1, end, index, map);

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;