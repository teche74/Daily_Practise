class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();    
        int n = matrix[0].size(); 

        for(int i = 0; i < m; ++i) {
            int mini = matrix[i][0];
            int col = 0;
            for(int j = 1; j < n; ++j) {
                if(matrix[i][j] < mini) {
                    mini = matrix[i][j];
                    col = j;
                }
            }

            bool check = true;
            for(int k = 0; k < m; ++k) {
                if(matrix[k][col] > mini) {
                    check = false;
                    break;
                }
            }

            if(check) {
                res.push_back(mini);
            }
        }

        return res;
    }
};
