class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low =  0 , high = 0 , size = nums.size();

        long long sum = 0;
        int res= 0;

        while(high < size){
            sum+=nums[high];

            int ele = (high - low +1);
            // dekh re last element * size of subarray dega ki operation ke bad array kesa hoga 
            
            // ab operation ke bad  - jessa vo abhi he unka difference mujhe btayega ki mujhe kitne changes krne he  
            long long if_oper = (long long)ele * nums[high];

            while(if_oper - sum > k){
                sum-=nums[low];
                low++;
                ele = (high - low +1);
                if_oper = (long long)ele * nums[high];
            }

            res = max( res , high - low + 1 );
            high++;
        }
        return res;
    }
};