class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;

        int left = 0 , top = 0 , right = matrix[0].size()-1 , bottom = matrix.size()-1;

        while(left <= right && top <= bottom){
            for(int i = left ; i<=right ; i++){
                res.emplace_back(matrix[top][i]);
            }
            top++;

            for(int i = top ; i<=bottom ; i++){
                res.emplace_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom){
                for(int i = right ; i >= left ;i--){
                    res.emplace_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right){
                for(int i = bottom ; i>= top ; i--){
                    res.emplace_back(matrix[i][left]);
                }
                left++;
            }
        } 

        return res;
    }
};