class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>map;

        for(int x : arr){
            map[x]++;
        }

        int res = -1;
        for(auto it : map){
            if(it.first == it.second){
                res = max(res,it.first);
            }
        }
        return res;
    }
};