class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1) return 0;
        int curr = 0 ,far = 0, jumps = 0;


        for(int i =0 ; i <size; i++){
            far = max(nums[i]+i, far);

            if(i == curr){
                curr = far;
                jumps++;

                if(curr >= size-1) return jumps;
            }
        }

        return jumps;
    }
};