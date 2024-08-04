class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>res;

        int size = nums.size();
        
        for(int i =0 ;i <size ; i++){
            long long sum = 0;
            for(int j = i;j <size;j++){
                sum+=nums[j];
                res.emplace_back(sum);
            }
        }

        sort(res.begin(), res.end());

        long long sum = 0;

        for(long long i = left-1 ; i < right ; i++){
            sum+=res[i];
            sum%=1000000007;
        }

        return sum;
    }
};