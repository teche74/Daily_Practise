class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int>res;

        int top = 0 , right = mat[0].size()-1 , left = 0 , bottom = mat.size()-1;

        while(top <= bottom && left <= right){
            
            for(int i = left ; i <=right ; i++){
                res.emplace_back(mat[top][i]);
            }
            top++;

            for(int i = top ; i<= bottom ; i++){
                res.emplace_back(mat[i][right]);
            }
            right--;

            if(top <= bottom){
                for(int i = right ; i>= left; i--){
                    res.emplace_back(mat[bottom][i]);
                }
                bottom--;
            }
            if(left <= right){
                for(int i=bottom ; i>= top ;i--){
                    res.emplace_back(mat[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};