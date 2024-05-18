class Solution {
public:
    int jump(vector<int>& nums) {
        int curr =0 , far = 0 , jumps = 0 , size = nums.size();
        if(size <= 1 ) return 0;

        for(int i =0 ; i < size ; i++){
            far = max(far, nums[i] + i);

            if(curr == i){
                curr= far;
                jumps++;

                if(curr  >= size-1){
                    return jumps;
                }
            }
        }

        return jumps;
    }
};