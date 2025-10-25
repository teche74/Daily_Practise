class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin() ,  nums.end());
        int diff = INT_MAX , res;

        for(int i = 0 ;  i < size; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = size-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > target){
                    k--;
                }    
                else if(sum < target){
                    j++;
                }
                else return target;

                if(diff > abs(sum - target)){
                    diff = abs(sum - target);
                    res = sum;
                }
            }
        }

        return res;
    }
};