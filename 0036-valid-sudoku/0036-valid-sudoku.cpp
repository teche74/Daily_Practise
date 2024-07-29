class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr) {
        int size = 9;

        int row[size][size], col[size][size], grid[size][size];
        memset(row,0, sizeof(row));
        memset(row,0, sizeof(col));
        memset(row,0, sizeof(grid));

        for(int i = 0 ; i < size; i ++){
            for(int j = 0 ;j <size; j++){
                if(arr[i][j] != '.'){
                    int val = arr[i][j] - '0';

                    int k = (i/3) * 3 + (j/3);

                    if(row[val-1][j]++ || col[i][val-1]++ || grid[val-1][k]++){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};