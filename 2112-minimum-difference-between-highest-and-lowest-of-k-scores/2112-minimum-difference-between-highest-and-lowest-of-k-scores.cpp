class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k <= 1) return  0;
        int res= INT_MAX ;

        sort(nums.begin(),nums.end());

        int size = nums.size();

        for(int i =0; i < size ; i++){
            if(i >= k-1){
                res  = min(res, nums[i] - nums[i-k+1]);
            }
        }
        return res;
    }

};