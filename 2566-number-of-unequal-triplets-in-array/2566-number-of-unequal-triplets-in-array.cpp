class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int size = nums.size();

        int cnt{0};

        for(int i =0; i < size; i++){
            for(int j =i+1;j  <size ; j++){
                for(int k = j+1 ; k <size; k++){
                    if(nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};