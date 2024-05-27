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

    void solve(int row, int len,  int &count, vector<string>temp){
        if(row == len){
            count++;
            return;
        }

        for(int col = 0 ; col < len ; col++){
            if(valid(temp,row,col,len)){
                temp[row][col] = 'Q';
                solve(row+1,len,count,temp);
                temp[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>temp(n,string(n,'.'));
        int count  = 0;

        solve(0,n,count,temp);

        return count;
    }
};
