class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m * n ) return {};

        vector<vector<int>>res;
        vector<int>temp;

        int i = 0, j = 0;

        for(int val : original){ 
            temp.push_back(val);
            j++;
            if(j == n){
                res.push_back(temp);
                temp.clear();
                i++;
                j=0;
            }
        }

        return res;

    }
};