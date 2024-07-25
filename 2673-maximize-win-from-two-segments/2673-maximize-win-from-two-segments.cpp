class Solution {
public:
    int maximizeWin(vector<int>& nums, int k) {
        int size =  nums.size();
        
        int pre[size];
        memset(pre,0 ,sizeof(pre));

        for(int i =0 ; i < size; i++){
            int val = nums[i];
            int j = upper_bound(nums.begin() , nums.end() , nums[i] + k) - nums.begin() ;

            pre[i] = j-i;
        }

        int dp[size+1];
        memset(dp,0 ,sizeof(dp));

        for(int i = size-1 ; i>= 0; i-- ){
            dp[i] = max(pre[i],dp[i+1]);
        }

        int res = 0 ;

        for(int i = 0; i < size; i++ ){
            int first = pre[i] ;

            int j = upper_bound(nums.begin() , nums.end() , nums[i] + k) - nums.begin() ;

            int second  = j < size ? dp[j] : 0;
            res  = max(res, first  + second);
        }
        return res;
    }
};