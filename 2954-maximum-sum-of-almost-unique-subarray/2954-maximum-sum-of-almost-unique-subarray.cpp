class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long low = 0 , high = 0 , size = nums.size(), res=  0, sum =0;

        unordered_map<int,int>map;

        while(high < size){
            sum += nums[high];
            map[nums[high]]++;
                // cout<<low<<" : "<<high<<endl;
                // cout<<sum<<endl;

            while(high - low+ 1 > k){
                sum-=nums[low];
                map[nums[low]]--;
                if(map[nums[low]] == 0){
                    map.erase(nums[low]);
                }
                low++;
            }

            if(map.size() >= m){
                res = max(res,sum);
            }

            high++;
        }

        return res;
    }
};