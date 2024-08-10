class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0 , res = INT_MIN;

        int low = 0 , high = 0 , size = nums.size () ;

        while(high < size ){
            sum += nums[high] ;
            
            if(high - low  + 1 >= k){
                // cout<<sum <<
                res  = max(res, sum/k);
                sum -= nums[low]; 
                low++;
            }
            high++;
        }  
        return res;
    }
};