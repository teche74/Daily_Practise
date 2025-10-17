class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size =  nums.size() , res = 0 , count = 2;

        int first = nums[0] , second  = nums[1];

        for(int i =2 ; i  < size; i++){

            if(first + second == nums[i]){
                count++;
            }
            else{
                count = 2;
            }
            res = max(res , count);
            
            first = second;
            second  = nums[i];
        } 

        

        return res;
    }
};