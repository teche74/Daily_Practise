class Solution {
public:
    const int _ = []()
    {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
    }();
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        _;
        int rows = rowSum.size();
        int cols = colSum.size();

        vector<vector<int>>res(rows,vector<int>(cols));

        for(int i =0 ; i <rows; i++){
            for(int j =0; j <cols ; j++){
                if(rowSum[i]  < colSum[j]){
                    res[i][j] = rowSum[i]; 
                }
                else if(rowSum[i]  >= colSum[j]){
                    res[i][j] = colSum[j];
                }
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }

        return res;
    }
};