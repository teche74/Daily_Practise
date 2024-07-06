class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();

        int curr = 0 , far = 0 ;

        for(int i =0 ;i <size; i++){
            far = max(far , nums[i]  +i);

            if(curr == i){
                curr = far;

                if(curr >= size-1) return true;
            }
        } 

        return false;
    }
};