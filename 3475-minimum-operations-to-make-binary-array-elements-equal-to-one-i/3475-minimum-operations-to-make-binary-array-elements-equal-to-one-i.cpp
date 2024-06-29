class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size();
        int moves = 0 ;

        for(int i = 0; i <= size - 3; i++){
            if(nums[i] == 0){
                moves++;
                if(i+3 > size) return -1;
                for(int j =0 ; j <= 2 ; j++)
                {
                    nums[i+j] = !nums[i+j];
                }
            } 
        }

        int sum = accumulate(nums.begin(), nums.end(),0);

        return sum == nums.size() ? moves : -1;

    }
};