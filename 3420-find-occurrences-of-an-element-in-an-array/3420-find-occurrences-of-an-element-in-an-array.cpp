class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>occur, res;

        for(int i =0 ;i  <nums.size() ; i++){
            if(nums[i] == x){
                occur.emplace_back(i);
            }
        }

        for(int x : queries){
            if(occur.size() < x){
                res.emplace_back(-1);
            }
            else{
                res.emplace_back(occur[x-1]);
            }
        }

        return res;
    }
};