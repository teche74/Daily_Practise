class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size()  , cols = matrix[0].size();

        vector<vector<int>>targets;

        for(int i = 0 ; i <rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(matrix[i][j] == 0){
                    targets.emplace_back(vector<int>{i,j});
                }
            }
        }

        if(targets.empty()) return ;

        for(auto t : targets){
            for(int i =  0; i < rows;  i++){
                matrix[i][t[1]] = 0;
            }

            for(int i = 0 ; i  <cols ; i++){
                matrix[t[0]][i] = 0;
            }
        }
    }
};