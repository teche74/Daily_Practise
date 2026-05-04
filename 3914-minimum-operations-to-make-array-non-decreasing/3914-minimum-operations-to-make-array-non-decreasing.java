class Solution {
    public long minOperations(int[] nums) {
        // long minopers = 0;
        // int size = nums.length;

        // for(int i = 0 ; i < size-1; i++){
        //     if(nums[i] > nums[i+1]){
        //         int j = i+1 , max_fix = nums[i] - nums[i+1];
        //         while(j < size && nums[j] < nums[i]){
        //             max_fix = Math.max(max_fix  , nums[i] - nums[j]);
        //             j++;
        //         }
        //         minopers += max_fix;
        //         i = j-1;
        //     }
        // }

        // return minopers;


         long ans = 0;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1]) {
                ans += nums[i - 1] - nums[i];
            }
        }

        return ans;
    }
}