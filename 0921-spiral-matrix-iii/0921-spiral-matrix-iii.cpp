class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int step = 1 ,dir = 0 , moved = 0 , eles = rows * cols;
        vector<vector<int>>res;
        res.push_back({rStart, cStart});

        while(res.size() < eles){

            for(int i =0; i < step ; i++){
                if (dir == 0) cStart++;       
                else if (dir == 1) rStart++;  
                else if (dir == 2) cStart--;  
                else if (dir == 3) rStart--;

                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    res.push_back({rStart, cStart});
                }
            }

            dir++;
            dir%=4;

            if(dir == 0  || dir == 2) step++;
        }
        return res;
    }
};