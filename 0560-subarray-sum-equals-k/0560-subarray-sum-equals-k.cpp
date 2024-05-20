class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int  size = nums.size();

        unordered_map<int,int>map;
        map[0] =1;

        int count  =0 , sum =0 ;

        for(int i =0 ; i <size; i++ ){
            sum += nums[i];

            if(map.find(sum - k) != map.end()){
                count+=map[sum-k];
            }

            map[sum]++;
        }
        return count;
    }
};