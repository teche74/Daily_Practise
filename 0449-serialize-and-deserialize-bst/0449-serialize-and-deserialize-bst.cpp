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
    void GetPostOrder(TreeNode * trav ,  vector<int> & res){
        if(trav){
            GetPostOrder(trav->left , res);
            GetPostOrder(trav->right , res);
            res.push_back(trav->val);
        }
    }

    void GetInOrder(TreeNode * trav ,  vector<int> & res){
        if(trav){
            GetInOrder(trav->left , res);
            res.push_back(trav->val);
            GetInOrder(trav->right , res);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int>inorder , postorder;
        GetInOrder(root , inorder);
        GetPostOrder(root , postorder);
        
        string res = "";

        for(int val : inorder){
            res += to_string(val);
            res.push_back('$');
        }

        res.push_back('*');

        for(int val : postorder){
            res += to_string(val);
            res.push_back('$');
        }

        return res;
    }


    TreeNode* CreateTree(int  & index , vector<int> &postorder , unordered_map<int,int>& index_map , int low, int high){
        if(low > high) return nullptr;

        int value = postorder[index--];
        int mid = index_map[value];

        TreeNode * root = new TreeNode(value);
        root->right = CreateTree(index , postorder , index_map, mid+1, high);
        root->left = CreateTree(index, postorder , index_map , low , mid-1);
        
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int low = 0 , high = 0 , size = data.size() , index = 0;
        unordered_map<int,int>map;
        bool cond = true;
        vector<int>postorder;

        while(high < size){
            if(data[high] == '$'){
                int val = stoi(data.substr(low , high - low));
                if(cond){
                    map[val] = index++;
                }
                else{
                    postorder.push_back(val);
                }
                low = high+1;
            }

            if(data[high] == '*'){
                cond = false;
                low = high+1;
            }
            high++;
        }

        index = postorder.size()-1;

        return CreateTree(index , postorder , map , 0 ,  postorder.size()-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;