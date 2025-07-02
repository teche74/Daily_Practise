/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    TreeNode* sortedListToBST(ListNode* head) {
        function<TreeNode *(ListNode* , ListNode*)> solve = [&](ListNode * low , ListNode * high)->TreeNode*{
            if(low == high) return nullptr;

            ListNode* slow = low , *fast = low;

            while(fast!=high && fast->next != high){
                slow = slow->next;
                fast = fast->next->next;
            }

            TreeNode * root = new TreeNode(slow->val);

            root->left = solve(low , slow);
            root->right = solve(slow->next,high);

            return root;
        };
        return solve(head, nullptr);
    }
};