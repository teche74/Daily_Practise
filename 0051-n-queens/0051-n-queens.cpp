class Solution {
public:
    bool valid(vector<string>temp , int row, int col, int size){
        for (int i = 0; i < row; i++) {
            if (temp[i][col] == 'Q') return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (temp[i][j] == 'Q') return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < size; i--, j++) {
            if (temp[i][j] == 'Q') return false;
        }

        return true;
    }
    void solve(int row, int len,  vector<vector<string>> & res, vector<string>temp){
        if(row == len){
            res.emplace_back(temp);
            return;
        }

        for(int col = 0 ; col < len ; col++){
            if(valid(temp,row,col,len)){
                temp[row][col] = 'Q';
                solve(row+1,len,res,temp);
                temp[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>temp(n,string(n,'.'));

        solve(0,n,res,temp);

        return res;
    }
};