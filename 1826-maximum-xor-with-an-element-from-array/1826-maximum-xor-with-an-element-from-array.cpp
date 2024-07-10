struct node{
    node * links[2] = {nullptr,nullptr};

    void CreateRef(int bit , node * n){
        links[bit] = n;
    }

    bool CheckRef(int bit){
        return links[bit] != nullptr;
    }

    node * GetRef(int bit){
        return links[bit];
    }
};

class Solution {
public:
    node *root = new node();
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        auto  Init = [&](int num){
            node *temp = root;
            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;
                if(!temp->CheckRef(bit)){
                    temp->CreateRef(bit, new node());
                }
                temp = temp->GetRef(bit);
            }
        };

        auto Query = [&](int num) {
            node *temp = root;
            int max_xr = 0;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (temp->CheckRef(1 - bit)) {
                    max_xr = max_xr | (1 << i);
                    temp = temp->GetRef(1 - bit);
                } else {
                    temp = temp->GetRef(bit);
                }
            }
            return max_xr;
        };

        sort(nums.begin(), nums.end());
        vector<int> result(queries.size(), -1);

        vector<pair<int, pair<int, int>>> mod_query;
        for (int i = 0; i < queries.size(); i++) {
            mod_query.push_back({queries[i][1], {queries[i][0], i}});
        }
        
        sort(mod_query.begin(), mod_query.end());

        int idx = 0;
        for (auto& q : mod_query) {
            int xi = q.second.first;
            int mi = q.first;
            int qid = q.second.second;
            while (idx < nums.size() && nums[idx] <= mi) {
                Init(nums[idx]);
                idx++;
            }
            if (idx > 0) {
                result[qid] = Query(xi);
            }
        }
        return result;

    }
};