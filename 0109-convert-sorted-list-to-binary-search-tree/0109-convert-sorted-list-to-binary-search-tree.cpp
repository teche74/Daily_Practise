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
    TreeNode * solve(int low, int high , vector<int> & arr){
        if(low > high ) return nullptr;

        int mid = low + (high - low)/2;

        TreeNode * root = new TreeNode(arr[mid]);

        root->left = solve(low,mid -1 , arr);
        root->right = solve(mid+1, high,arr);

        return root;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>res;

        ListNode * temp = head;

        while(temp){
            res.emplace_back(temp->val);
            temp=temp->next;
        }

        return solve( 0, res.size()-1 , res );
    }
};