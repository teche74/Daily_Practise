class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int size = candidates.size();

        function<void(int , int)> solve =[&](int index , int target){
            if(index >= size){
                if(!target){
                    res.push_back(temp);
                }
                return;
            }
            
            if(candidates[index] <= target){
                temp.push_back(candidates[index]);
                
                solve(index , target - candidates[index]);
                
                temp.pop_back();
            }
            
            solve(index+1, target);
            
        };

        solve(0 , target);
        return res;
    }
};