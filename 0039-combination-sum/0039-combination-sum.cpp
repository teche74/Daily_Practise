class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int size = candidates.size();

        function<void(int , int)> call = [&](int index , int target){
            if(index >= size){
                if(!target){
                    res.push_back(temp);
                }
                return;
            }

            if(target - candidates[index] >= 0){
                temp.push_back(candidates[index]);
                call(index , target - candidates[index]);
                temp.pop_back();
            }

            call(index+1 , target);
        };


        call(0 , target);
        return res;
    }
};