class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size =  nums.size();

        unordered_map<int,int>map;
        int cnt{0}, ind =0;

        for(int i =0; i <size ; i++){
            if(map.find(nums[i]) == map.end() || map[nums[i]] < 2){
                map[nums[i]]++;
                nums[ind] = nums[i];
                ind++;
                cnt++;
            }
        }
        return cnt;
    }
};