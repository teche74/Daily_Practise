class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size  = nums.size();

        vector<vector<int>>res;

        sort(nums.begin(), nums.end());


        for(int i =0 ;i  <size ; i++){
            if( i> 0  && nums[i] == nums[i-1]) continue;

            int j = i+1;
            int k = size-1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0){
                    vector<int>temp = {nums[i], nums[j], nums[k]};
                    res.emplace_back(temp);

                    j++;
                    k--;

                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return res;
    }
};