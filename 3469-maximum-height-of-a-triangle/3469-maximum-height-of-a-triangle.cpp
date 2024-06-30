class Solution {
public:
    int solve(int cap1, int cap2){
        int curr_cap =1 , height =0 ;
        bool turn  =true;

        while(true){
            if(turn){
                if(curr_cap <= cap1){
                    cap1-=curr_cap;
                    turn  = !turn;
                    height++;
                    curr_cap++;
                }
                else{
                    break;
                }
            }
            else{
                if(curr_cap <= cap2){
                    cap2-=curr_cap;
                    turn  = !turn;
                    height++;
                    curr_cap++;
                }
                else{
                    break;
                }
            }
        }
        return height;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red, blue), solve(blue,red));
    }
};