class Solution {
public:

    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());


        int size = nums.size();
        vector<int>pre(size,0);

        pre[0] = nums[0];

        for(int i =1; i < size; i++ ){
            pre[i] = pre[i-1]+ nums[i];
        }

        vector<int>res;
        int sum = 0;

        for(int i = size-1 ;i>= 0; i--){
            sum+=nums[i];
            res.emplace_back(nums[i]);
            if(i == 0 || sum > pre[i-1]){
                return res;
            }
        }
        return res;
    }
};