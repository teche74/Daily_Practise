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
    bool DifferentParent(TreeNode * root, int x, int y){
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            bool first = false, second = false , same_parent = false;

            for(int i = 0; i < size; i++){
                TreeNode *front = q.front();
                q.pop();

                if(front->val == x){
                    first = true;
                }

                if(front->val == y){
                    second = true;
                }

                if(front->left && front->right){
                    if(front->left->val == x && front->right->val == y || front->left->val == y && front->right->val == x){
                        same_parent = true;
                    }
                }

                if(front->left){
                    q.push(front->left);
                }

                if(front->right){
                    q.push(front->right);
                }
            }

            if(first && !second || second && !first){
                return false;
            }

            if(same_parent){
                return false;
            }
        }
        return true;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        return DifferentParent(root,x,y);
    }
};