class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int>pre(size,0),suff(size,0);

        pre[0] = nums[0] , suff[size-1] = nums[size-1];

        for(int i = 1 ; i < size ; i++){
            pre[i] = pre[i-1] * nums[i];
            suff[size-i-1] = suff[size-i] * nums[size- i -1];
        }


        vector<int>res(size,0);
        res[0] = suff[1], res[size-1] = pre[size-2];

        for(int i = 1; i < size-1; i++){
            res[i] = (pre[i-1] * suff[i+1]);
        }

        return res;
    }
};