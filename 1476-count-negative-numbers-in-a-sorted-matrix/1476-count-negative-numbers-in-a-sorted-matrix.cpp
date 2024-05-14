class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count  =0 ; 

        int rows = grid.size(), cols = grid[0].size();

        for(int i = 0 ; i <rows; i++){
            
            int index = cols;

            for(int j = cols ; j>=1 ;j/=2){
                while(index-j >= 0 && grid[i][index-j] <0) index-=j;
            }
            count += (cols - index);
        }

        return count;

    }
};