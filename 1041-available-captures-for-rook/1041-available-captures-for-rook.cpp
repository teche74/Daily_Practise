class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        for(int i= 0; i< board.size() ; i++){
            for(int j =0; j < board[0].size() ; j++){
                if(board[i][j] == 'R'){
                    int count = 0;
                    for(int k =i+1 ; k < board.size(); k++){
                        if(islower(board[k][j])){
                            count++;
                            break;
                        }
                        else if(isupper(board[k][j])) break;
                    }

                    for(int k =i-1 ; k >=0 ; k--){
                        if(islower(board[k][j])){
                            count++;
                            break;
                        }
                        else if(isupper(board[k][j])) break;
                    }

                    for(int k =j+1 ; k < board[0].size(); k++){
                        if(islower(board[i][k]))if(islower(board[i][k])){
                            count++;
                            break;

                        }
                        if(isupper(board[i][k])) break;
                    }
                    for(int k =j-1 ; k >=0 ; k--){
                        if(islower(board[i][k])){
                            count++;
                            break;
                        }
                        if(isupper(board[i][k])) break;
                    }

                    return count;
                }
            }
        }
        return  0;
    }
};