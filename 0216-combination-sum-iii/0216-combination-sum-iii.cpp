class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>temp;

        function<void(int, int)>call = [&](int index , int target){
            if(temp.size() == k){
                if(!target){
                    res.push_back(temp);
                }
                return;
            }

            for(int i = index ; i <= 9;  i++){
                if(target - i < 0)break;
                temp.push_back(i);
                call(i+1 , target - i);
                temp.pop_back();
            }
        };

        call(1 , n);
        return res;
    }
};