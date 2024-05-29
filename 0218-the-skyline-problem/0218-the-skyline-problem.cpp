#define ll long long

struct Node {
    ll l, r, val;
    Node *left, *right;
    Node(ll x, ll y, ll v) : l(x), r(y), val(v), left(NULL), right(NULL) {}
};

class SegTree {
    Node* root;
public:
    SegTree() {
        root = new Node(0, (1LL << 31), 0);
    }

    void update(ll l, ll r, ll val, Node* root) {
        if (l >= root->r || r <= root->l) {
            // No overlap
            return;
        }
        if (l <= root->l && root->r <= r) {
            // Total overlap
            root->val = max(root->val, val);
            if (!root->left) { // leaf node
                return;
            }
        }
        if (!root->left) {
            // Create children nodes
            ll mid = (root->l + root->r) / 2;
            root->left = new Node(root->l, mid, root->val);
            root->right = new Node(mid, root->r, root->val);
        }
        // Update children nodes
        update(l, r, val, root->left);
        update(l, r, val, root->right);
    }

    void addBuilding(const vector<int>& building) {
        update(building[0], building[1], building[2], root);
    }

    void getSkyline(Node* root, vector<vector<ll>>& skyline) {
        if (!root->left) {
            skyline.push_back({root->l, root->r, root->val});
            return;
        }
        getSkyline(root->left, skyline);
        getSkyline(root->right, skyline);
    }

    vector<vector<int>> generateSkyline() {
        vector<vector<ll>> tempSkyline;
        getSkyline(root, tempSkyline);

        vector<vector<int>> result;
        int prevHeight = 0;
        for (const auto& segment : tempSkyline) {
            if (segment[2] != prevHeight) {
                result.push_back({static_cast<int>(segment[0]), static_cast<int>(segment[2])});
                prevHeight = segment[2];
            }
        }
        // Ensure the skyline ends at height 0
        if (!result.empty() && result.back()[1] != 0) {
            result.push_back({static_cast<int>(tempSkyline.back()[1]), 0});
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        SegTree segTree;
        for (const auto& building : buildings) {
            segTree.addBuilding(building);
        }
        return segTree.generateSkyline();
    }
};
