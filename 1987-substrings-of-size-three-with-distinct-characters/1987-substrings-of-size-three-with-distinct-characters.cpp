class Solution {
public:
    int countGoodSubstrings(string s) {
        int low = 0, high = 0 , size = s.size();

        unordered_map<char,int>map;

        while(high < 3 ){
            map[s[high]]++;
            high++;
        }

        int count = 0;
        if(map.size() == 3) count++;
        
        while(high < size){
            map[s[high]]++;
            map[s[low]]--;
            if(map[s[low]] == 0){
                map.erase(s[low]);
            }
            if(map.size() == 3) count++;
            low++;
            high++;   
        }

        return count;
    }
};