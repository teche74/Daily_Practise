class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();

        if(size == 1) return true;

        int curr = 0 , far = 0;

        for(int i = 0; i <size; i++ ){
            far = max(far, i + nums[i]);

            if(i == curr){
                curr =far;


                if(curr >= size-1) return true;
            }
        } 
        return false;
    }
};