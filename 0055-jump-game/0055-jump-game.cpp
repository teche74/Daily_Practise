class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = 0 , far = 0 ;

        for(int i =0; i < nums.size() ; i++){
            far = max(far,nums[i] + i);

            if(curr == i){
                curr = far;

                if(curr >= nums.size()-1) return true;
            }
        }
        return false;
    }
};