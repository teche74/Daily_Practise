class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        if(nums1 == nums2) return 0;

        function<string(vector<int> &)> hash = [&](vector<int> & arr){
            string res = "";
            
            for(int x : arr){
                res += x + ',';
            }


            return res;
        };

        auto gen_states =[&](vector<int> & arr){
            int size = arr.size();
            vector<vector<int>>states;
            for(int i = 0 ; i < size; i++){
                for(int j = i; j < size;j++){
                    vector<int> sub(arr.begin() + i, arr.begin() + j + 1);
                    vector<int> remain;
                    remain.insert(remain.end(), arr.begin(), arr.begin() + i);
                    remain.insert(remain.end(), arr.begin() + j + 1, arr.end());

                    for (int pos = 0; pos <= (int)remain.size(); ++pos) {
                        vector<int> candidate = remain;
                        candidate.insert(candidate.begin() + pos, sub.begin(), sub.end());
                        states.push_back(candidate);
                    }
                }
            }

            return states;
        };


        queue<pair<vector<int>, int>> q;
        unordered_set<string> vis;

        q.push({nums1 , 0});
        vis.insert(hash(nums1));

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            for (auto& next : gen_states(current)) {
                if (next == nums2) return steps + 1;
                string key = hash(next);
                if (!vis.count(key)) {
                    vis.insert(key);
                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};