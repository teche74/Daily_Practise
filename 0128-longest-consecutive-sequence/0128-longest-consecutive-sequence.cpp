class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int>map;

        for(int x : nums){
            map[x]++;
        }

        int res = 0 ;

        for(auto t : nums){
            if(map.find(t-1) == map.end()){
                int val = t;
                int count  = 1;
                while(map.find(val+1) != map.end()){
                    val++;
                    count++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};