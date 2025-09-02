class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& values, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int size = values.size();
        sort(values.begin() ,  values.end());

        function<void(int , int)> call = [&](int index , int target){
            
            if(!target){
                res.push_back(temp);
                return;
            }

            for(int i = index; i < size ; i++){
                if(i > index && values[i] == values[i-1]) continue;
                if(target - values[i] < 0) break;
                temp.push_back(values[i]);
                call(i+1, target - values[i]);
                temp.pop_back();
            }
        };


        call(0 , target);
        return res;
    }
};