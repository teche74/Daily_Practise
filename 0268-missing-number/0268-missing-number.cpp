class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort and find
        // sort(nums.begin() , nums.end());
        // int size=  nums.size();

        // for(int i = 0; i < size ; i ++){
        //     if(nums[i] != i) return i;
        // }

        // return nums.size();


        // using visit 

        unordered_map<int,int>map;
        int size = nums.size();

        for(int val : nums){
            map[val]++;
        } 

        for(int i = 0 ; i < size ; i++){
            if(map.find(i) == map.end()) return i;
        }
        return size;
    }
};