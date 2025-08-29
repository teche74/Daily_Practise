class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>map;

        for(int val : nums){
            map[val]++;

            if(map[val] > 1){
                return val;
            }
        }

        return -1;
    }
};