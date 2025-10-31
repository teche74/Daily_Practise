class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>map;

        for(int x : nums) map[x]++;

        vector<int>res(2, -1);

        for(auto t : map){
            if(t.second > 1){
                if(res[0] == -1){
                    res[0] = t.first;
                }
                else{
                    res[1] = t.first;
                    break;
                }
            }
        }

        return res;
    }
};