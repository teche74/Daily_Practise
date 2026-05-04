class Solution {
    public int[] countOppositeParity(int[] nums) {
        int size = nums.length;
        int[] res = new int[size];


        for(int i = 0; i < size ; i++){
            if(nums[i] % 2 != 0){
                int j = i+1 , score = 0;
                while(j < size){
                    score += (nums[j] % 2 == 0) ? 1 : 0;
                    j++;
                }

                res[i] = score;
            }
            else{
                int j = i+1 , score = 0;
                while(j < size){
                    score += (nums[j] % 2 != 0) ? 1 : 0;
                    j++;
                }

                res[i] = score;
            }
        }

        return res;
    }
}