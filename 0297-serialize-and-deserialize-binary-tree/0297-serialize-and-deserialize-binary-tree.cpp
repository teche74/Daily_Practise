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

    void pre(TreeNode* root, vector<string>& preorder) {
        if (!root) {
            preorder.push_back("#"); 
            return;
        }
        preorder.push_back(to_string(root->val));
        pre(root->left, preorder);
        pre(root->right, preorder);
    }

    string serialize(TreeNode* root) {
        vector<string> preorder;
        pre(root, preorder);

        string res = "";
        for (auto& s : preorder) {
            res += s + '.';
        }
        return res;
    }

    TreeNode* deserialize(string data) {
        vector<string> preorder;
        stringstream ss(data);
        string item;

        while (getline(ss, item, '.')) {
            if (!item.empty()) {
                preorder.push_back(item);
            }
        }
        
        int index = 0;
        return buildTree(preorder, index);
    }

    TreeNode* buildTree(vector<string>& preorder, int& index) {
        if (index >= preorder.size() || preorder[index] == "#") {
            index++; // Move past the marker
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(preorder[index++]));
        node->left = buildTree(preorder, index);
        node->right = buildTree(preorder, index);

        return node;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));