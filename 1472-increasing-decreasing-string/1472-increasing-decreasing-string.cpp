class Solution {
public:
    string sortString(string s) {
        string res = "";

        unordered_map<char,int>map;

        for(char ch : s) map[ch]++;

        string uni = "";
        
        for(auto t : map){
            uni.push_back(t.first);
        }

        sort(uni.begin(),uni.end());

        int ind = 0, helper = 1;

        while(res.size() < s.size()){
                
            if(map[uni[ind]]  > 0){
                res.push_back(uni[ind]);
                map[uni[ind]]--;
            }

            ind+=helper;
            
            if(ind == uni.size() || ind == -1){
                helper*=-1;
                ind+=helper;
            }

        }

        return res;
    }
};