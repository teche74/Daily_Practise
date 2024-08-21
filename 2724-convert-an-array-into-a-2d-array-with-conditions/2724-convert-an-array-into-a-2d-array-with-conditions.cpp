class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return {}; 

        unordered_map<int,int>freq;

        for(auto t  : nums){
            freq[t]++;
        }

        vector<vector<int>>res;

        while(!freq.empty()){
            vector<int>temp;
            for(auto it= freq.begin() ; it != freq.end();){
                temp.emplace_back(it->first);
                it->second--;

                if (it->second == 0) {
                    it = freq.erase(it); 
                } else {
                    ++it;
                }
            }
            res.emplace_back(temp);
        }

        return res;
    }
};