class Solution {
public:
    vector<vector<int>> dirs = {{0,-1} , {1,0} , {-1,0} , {0,1}};
    void bfs(vector<vector<int>>& image, int prev , int new_col , int row, int col){
        if(row < 0 || col < 0 || row >= image.size() || col >= image[0].size() || image[row][col] != prev){
            return;
        }

        image[row][col] = new_col;


        for(auto t : dirs){
            int new_r = row + t[0];
            int new_c = col + t[1];

            bfs(image,prev,new_col , new_r,new_c);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev = image[sr][sc];

         if (prev != color) {
            bfs(image, prev, color, sr, sc);
        }

        return image;
    }
};