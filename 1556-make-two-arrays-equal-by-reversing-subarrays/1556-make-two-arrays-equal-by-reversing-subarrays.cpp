class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>map;

        for(auto t : target){
            map[t]++;
        }

        for(auto t : arr){
            if(map.find(t) == map.end()) return false;
            map[t]--;
        }

        for(auto t : map){
            if(t.second > 0) return false;
        }

        return true;
    }
};