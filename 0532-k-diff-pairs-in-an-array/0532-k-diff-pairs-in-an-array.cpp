class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if( k < 0) return 0;
        unordered_map<int,int>map;

        int count = 0;

        for(auto t : nums){
            map[t]++;
        }

        for(auto t : map){
            if(k ==0){
                if(t.second >1){
                    count++;
                }
            }
            else{
                if(map.find(t.first + k) != map.end()){
                    count++;
                }
            }
        }
        return count;
    }
};