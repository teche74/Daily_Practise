class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int size = nums.size(), res = INT_MAX;

        for(int i = 0; i < size ; i++){
            int val = 0;

            for(int j = i ; j < size ;j++){
                val |= nums[j];

                if(val >= k){
                    res = min(res, j- i +1);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};