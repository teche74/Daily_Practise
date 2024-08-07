class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if(!size) return 0;

        double pre  = 1 ,  suff =1 , res  =INT_MIN;

        for(int i = 0 ;i < size ; i++ ){
            if(pre == 0){
                pre =1;
            }

            pre *= nums[i];
            res = max(res, pre);
        }

        for(int i = size -1; i>= 0; i--){
            if(suff == 0){
                suff = 1;
            }

            suff *= nums[i];
            res = max(res, suff);
        }
        return res;
    }
};