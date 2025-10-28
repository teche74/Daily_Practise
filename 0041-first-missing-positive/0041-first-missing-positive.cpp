class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size=  nums.size();

        for(int i = 0 ; i < size; i++){
            while( nums[i] > 0 && nums[i] < size && nums[nums[i]-1] != nums[i]){
                swap(nums[i] , nums[nums[i]-1]);
            }
        }

        int index = 0 , val = 1;

        while(index < size){
            if(nums[index] == val){
                val++;
            }
            else if(nums[index] > val){
                break;
            }
            index++;
        }
        return val;
    }
};