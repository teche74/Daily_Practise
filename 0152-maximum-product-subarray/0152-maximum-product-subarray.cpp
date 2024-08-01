class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;

        double pre = 1 , suff =1 , res = INT_MIN;

        for(int i = 0; i < size ;i++){
            if(pre == 0){
                pre =1;
            }
            if(suff == 0){
                suff =1;
            }
            pre = pre * nums[i];
            suff = suff * nums[size-i-1];
            res = max(res, max(pre,suff));
        }

        return res;
    }
};