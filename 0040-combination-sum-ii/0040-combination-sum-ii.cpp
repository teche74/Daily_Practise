class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int size = cand.size();

        sort(cand.begin(),cand.end());


        function<void(int,int)> solve = [&](int index, int val){

            if(val == 0){
                res.emplace_back(temp);
                return;
            }


            for(int i =  index ; i < size ; i++){
                if(i > index && cand[i] == cand[i-1]) continue;
                if(cand[i] > val) break;
                temp.emplace_back(cand[i]);
                solve(i+1,val-cand[i]);
                temp.pop_back();
            }
        };

        solve(0,target);

        return res;
    }
};