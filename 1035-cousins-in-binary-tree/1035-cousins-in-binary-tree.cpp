/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool same_level(TreeNode* root, int x, int y) {
        if (!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            bool got_1 = false, got_2 = false;
            
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                
                if (front->val == x) got_1 = true;
                if (front->val == y) got_2 = true;
                
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
            
            if (got_1 && got_2) return true;
            if (got_1 || got_2) return false;
        }
        
        return false;
    }
    
    bool solve(TreeNode* root, int x, int y){
        if(!root) return true;

        bool left = solve(root->left,x,y);
        bool right = solve(root->right,x,y);

        if(root->left && root->right && (root->left->val == x && root->right->val == y || root->left->val == y && root->right->val == x) ){
            return false;
        }

        return left && right;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(!same_level(root,x,y)) return false;

        return solve(root, x,y);
    }
};