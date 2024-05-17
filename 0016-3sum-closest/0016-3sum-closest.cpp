class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size  = nums.size();

        sort(nums.begin(), nums.end());

        int res = 0, min_diff = INT_MAX;


        for(int i =0 ;i  <size ; i++){
            if( i> 0  && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = size-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == target) return sum;

                else if(sum > target){
                    k--;
                }
                else{
                    j++;
                }

                if(abs(target - sum) < min_diff){
                    min_diff = abs(target  - sum);
                    res = sum;
                }
            }
        }
        return res;
    }
};