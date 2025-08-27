#define loop(i, start, end , step) for(int i = start ; i < end ; i+=step)
#define pb push_back
#define cond(value) if(value == 0)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size() , cols = matrix[0].size();

        vector<pair<int,int>>indices;

        loop(i, 0,rows, 1){
            loop(j, 0, cols,1){
                cond(matrix[i][j]){
                    indices.pb({i,j});
                }
            }
        }

        function<void(int, int)>make_zero = [&](int row, int col)->void{
            for(int i = 0; i < rows ; i++){
                matrix[i][col] = 0;
            }
            for(int j = 0 ; j < cols ; j++){
                matrix[row][j] = 0;
            }
        };

        for(auto index_pair : indices){
            make_zero(index_pair.first, index_pair.second);
        }
    }
};