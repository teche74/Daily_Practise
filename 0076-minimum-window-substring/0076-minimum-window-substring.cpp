class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>map;

        for(auto x : t){
            map[x]++;
        }

        int low = 0 , high =  0, size = s.size() , ind = 0 , len = INT_MAX;
        int count = map.size(); 

        while(high < size){
            if(map.find(s[high]) != map.end()){
                map[s[high]]--;
                count -= (map[s[high]] == 0);
            }

            while(count == 0){
                if(high - low +1 < len){
                    len = high - low +1;
                    ind = low;
                }

                if(map.find(s[low]) != map.end()){
                    map[s[low]]++;
                    count+=(map[s[low]] == 1);
                }
                low++;
            }
            high++;
        } 

        return len == INT_MAX ? "" : s.substr(ind,len);
    }
};