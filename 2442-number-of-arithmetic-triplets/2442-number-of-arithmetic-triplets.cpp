class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int size = nums.size();

        unordered_map<int,int>map;

        for(int i = 0 ; i < size; i++){
            map[nums[i]]++;
        }

        int res = 0;

        for(int i : nums){
            
            if(map.find( diff + i ) != map.end() && map.find( (diff << 1) + i ) != map.end()){     
                res++;
            }
        }

        return res;
    }
};