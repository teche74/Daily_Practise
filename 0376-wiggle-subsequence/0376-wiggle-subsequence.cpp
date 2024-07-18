class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();

        int prev_diff = 0 , curr_diff = 0, count = 1;

        for(int i = 0; i < size-1 ; i++){
            curr_diff = nums[i] - nums[i+1];

            if(curr_diff >= 0 && prev_diff < 0 ){
                prev_diff = curr_diff;
                count++;
            } 
            else if(curr_diff < 0 && prev_diff >= 0){
                prev_diff =  curr_diff;
                count++;
            }
        } 
        return count;
    }
};