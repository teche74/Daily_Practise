class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long res = 0, xr= 0, size = nums.size() ;

        unordered_map<int,long long>map;

        map[0]=1;

        for(int i =0 ;i  <size; i++){
            xr ^= nums[i];

            if(map.count(xr)){
                res+= map[xr];
            }

            map[xr]++;
        }

        return res;
    }
};