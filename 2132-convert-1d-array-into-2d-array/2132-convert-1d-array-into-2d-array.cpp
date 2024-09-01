class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n ) return {};
        vector<vector<int>>res;

        int k = 0;

        for(int i = 0 ; i <  m ; i++){
            vector<int>temp;
            for(int j = 0 ; j <n ; j++){
                temp.emplace_back(original[k++]);
            }
            res.emplace_back(temp);
                if(i >= original.size()){
                    break;
                }
        }

        return res;
    }
};