class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>res;

        sort(nums.begin(), nums.end());

        vector<int>pre;
        int size = nums.size();

        for(int x : nums){
            pre.emplace_back(pre.empty() ? x : pre.back() + x);
        }

        for(auto t : queries){
            
            int index = 0;

            for(int j = size ; j >= 1 ; j/=2){
                while(index + j < size && pre[index + j] <= t) index+=j;
            }

            if(pre[index] > t){
                res.emplace_back(0);
            }
            else
                res.emplace_back(index+1);
        }

        return res;
    }
};