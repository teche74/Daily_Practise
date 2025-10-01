class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int size = nums.size();

        bool prefix[size] , suffix[size];
        memset(prefix, false,  sizeof(prefix));
        memset(suffix, false,  sizeof(suffix));

        prefix[0] = true , suffix[size-1] = true;

        for(int i =  1 ; i < size; i++){
            if(nums[i] > nums[i-1] && prefix[i-1]){
                prefix[i] = true;
            }
            
            if(nums[size-i-1] > nums[size-i] && suffix[size-i]){
                suffix[size-i-1] = true; 
            }
        }

        long long sum = 0 , left = 0  , res = LLONG_MAX;
        
        for(int x  : nums){
            sum += x;
        }
        
        for(int i = 0; i < size-1 ; i++){
            sum -= nums[i];
            left += nums[i];

            if(prefix[i] && suffix[i +1]){
                res = min(res , llabs(sum - left));
            }
        }

        return res == LLONG_MAX  ? -1 : res;
    }
};