#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int rows = 7 , cols = 7;
    vector<vector<bool>>vis(rows, vector<bool>(cols , false));

    function<int(int, int,int)> solve =[&](int index , int row , int col)->int{ 
        if(index >= 48){
            if(row == 6  && col == 0) return 1;
            return 0;
        }
        
        // cout<<row<<" "<<col<<"  ->  ";
        vis[row][col] = true;

        if ((row == 0 || vis[row-1][col]) &&
            (row == 6 || vis[row+1][col]) &&
            col > 0 && !vis[row][col-1] &&
            col < 6 && !vis[row][col+1]) {
            vis[row][col] = false;
            return 0;
        }


        if ((col == 0 || vis[row][col-1]) &&
            (col == 6 || vis[row][col+1]) &&
            row > 0 && !vis[row-1][col] &&
            row < 6 && !vis[row+1][col]) {
            vis[row][col] = false;
            return 0;
        }

        if (row > 0 && col < 6 && vis[row-1][col+1] && !vis[row-1][col] && !vis[row][col+1]) {
            vis[row][col] = false;
            return 0;
        }
        if (row < 6 && col < 6 && vis[row+1][col+1] && !vis[row+1][col] && !vis[row][col+1]) {
            vis[row][col] = false;
            return 0;
        }
        if (row > 0 && col > 0 && vis[row-1][col-1] && !vis[row-1][col] && !vis[row][col-1]) {
            vis[row][col] = false;
            return 0;
        }
        if (row < 6 && col > 0 && vis[row+1][col-1] && !vis[row+1][col] && !vis[row][col-1]) {
            vis[row][col] = false;
            return 0;
        }

        int total = 0;

        if(str[index] != '?'){
            int new_row = row, new_col = col;
            switch (str[index])
            {
                case 'U':
                    new_row--;
                    break;
                case 'D':
                    new_row++;
                    break;
                case 'L':
                    new_col--;
                    break;
                case 'R':
                    new_col++;
                    break;
            }
            if(new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && !vis[new_row][new_col])
                total += solve(index+1 , new_row, new_col);
        }
        else{
            for(auto t : vector<vector<int>>{{0,1} , {1,0} , {-1,0} , {0,-1}}){
                int new_row = row + t[0];
                int new_col = col + t[1];

                if(new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols || vis[new_row][new_col]) continue;

                total += solve(index+1, new_row, new_col);
            }
        }

        vis[row][col] = false;
        return total;
    };

    while(cin >> str){
        vis = vector<vector<bool>>(rows, vector<bool>(cols, false));
        int res = solve(0, 0, 0);

        cout<<res<<endl;
    }
}