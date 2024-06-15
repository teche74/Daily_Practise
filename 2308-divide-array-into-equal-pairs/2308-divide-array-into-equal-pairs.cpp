class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>map;

        for(int x : nums){
            map[x]++;
        }

        int uni = 0;

        for(auto t : map){
            uni += (t.second % 2);

            if(uni == 1) return false;
        }
        
        return true;
    }
};