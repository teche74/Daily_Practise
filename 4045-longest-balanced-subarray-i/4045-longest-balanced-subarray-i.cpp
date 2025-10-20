class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int size  = nums.size();
        int res = 0;

        for(int i = 0 ; i < size ; i++){
            int index = i;
            unordered_map<int,int>even , odd;

            while(index < size){
                if(nums[index] & 1){
                    odd[nums[index]]++;
                }
                else{
                    even[nums[index]]++;
                }

                if(even.size() == odd.size()){
                    res = max(res , index - i  +1);
                }
                index++;
            }
        }

        return res;
    }
};