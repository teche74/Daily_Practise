class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& arr) {
        int size = arr.size();

        int rgrid[size][size];
        int cgrid[size][size];
        int ggrid[size][size];

        memset(rgrid,0, sizeof(rgrid));
        memset(cgrid,0, sizeof(rgrid));
        memset(ggrid,0, sizeof(rgrid));

        for(int i =0 ; i <size; i++){
            for(int j  =0 ; j <size; j++){
                if(arr[i][j] != '.'){
                    int val = arr[i][j] - '0';

                    int k = (i/3)*3 + j/3;


                    if(rgrid[i][val-1]++ || cgrid[val-1][j]++ || ggrid[k][val-1]++){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};