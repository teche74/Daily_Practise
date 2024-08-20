class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 0) return 0;

        double res = INT_MIN ;

        double prev = 1 , suff = 1;

        for(int i = 0 ;i  <size; i++){
            if(prev == 0) prev = 1;
            if(suff == 0) suff = 1;

            suff *= nums[size-i-1];
            prev *= nums[i];

            res = max(res, max(prev, suff));
        }

        return res;
    }
};