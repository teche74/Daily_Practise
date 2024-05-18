class Solution {
public:
    bool valid(vector<vector<char>>&arr, int row, int col, char ch){
        for(int i =0 ;i < 9 ; i++){
            if(arr[row][i] == ch) return false;
            if(arr[i][col] == ch) return false;
            if(arr[(row/3)*3 + (i/3)][(col/3)*3 + (i%3)] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>&arr){
        int size = arr.size();

        for(int i =0 ; i < size; i++){
            for(int j = 0; j < size ; j++)
            {
                if(arr[i][j] == '.'){
                    for(char ch = '1' ; ch <= '9' ;ch++){
                        if(valid(arr,i,j, ch) == true){
                            arr[i][j] = ch;

                            if(solve(arr) == true) return true;
                            else arr[i][j] ='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& arr) {
        solve(arr);
    }
};