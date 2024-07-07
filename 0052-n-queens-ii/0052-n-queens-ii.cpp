class Solution {
    bool check(vector<string>temp,int row, int col){
        for (int i = 0; i < row; ++i) {
            if (temp[i][col] == 'Q') return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (temp[i][j] == 'Q') return false;
        }


        for (int i = row, j = col; i >= 0 && j < temp.size(); --i, ++j) {
            if (temp[i][j] == 'Q') return false;
        }

        return true;
    }
    void solve(int row, int size, vector<string>temp, int & res){
        if(row == size){
            res ++;
            return;
        }

        for(int col = 0; col < size; col++){
            if(check(temp,row,col)){
                temp[row][col] = 'Q';
                solve(row+1,size,temp,res);
                temp[row][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<string>temp(n, string(n,'.'));

        solve(0,n,temp,res);

        return res;
    }
};
