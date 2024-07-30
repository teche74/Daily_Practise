class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        vector<vector<int>>targets;

        int rows = mat.size(), cols = mat[0].size();

        for(int i = 0; i < rows ; i++){
            for(int j = 0; j < cols;  j++){
                if(mat[i][j] == 0){
                    targets.push_back({i,j});
                }
            }
        }

        // if(targets.size() == rows * cols){
        //     mat[rows][cols] = {0};
        //     return;
        // }

        if(targets.empty()) return ;

        for(auto t : targets){
            int row = t[0] , col = t[1];
            for(int i = 0 ; i < cols ; i++){
                mat[row][i] = 0;
            }

            for(int i = 0 ;i  <rows ; i++){
                mat[i][col] = 0;
            }
        }


    }
};