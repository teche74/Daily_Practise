class Solution {
public:
    int solve(vector<int> & nums, int odds){
        int low =0 , high = 0 , size= nums.size() ,res = 0, count=  0;

        while(high < size){
            count+=(nums[high] & 1);

            while(count > odds){
                count-=(nums[low] & 1);
                low++;
            }

            res+=(high - low+1);

            high++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return  solve(nums, k) - solve(nums, k-1);
    }
};