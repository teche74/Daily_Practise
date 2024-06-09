class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>map;

        map[0] =1;

        int sum = 0,res= 0;

        for(int i =0;i < nums.size() ;i++){
            sum+=nums[i];
            int rem = sum % k;

            if(rem < 0){
                rem+=k;
            }

            if(map.find(rem) != map.end()){
                res+=map[rem];
            }

            map[rem]++;
        }

        return res;
    }
};