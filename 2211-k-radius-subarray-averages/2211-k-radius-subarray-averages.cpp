class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int>res(size,-1);

        int ind = k;

        long long low = 0 , high = 0 , sum = 0, len = 2 * k + 1;

        while(high < size){
            sum+=nums[high];

            while(high - low + 1 > len){
                sum-=nums[low];
                low++;
            }

            if(high - low + 1 == len){
                res[ind] = (sum)/len;
                ind++;
            }
            high++;
        }
        return res;
    }
};