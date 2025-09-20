class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>map;

        for(char ch  : t) map[ch]++;

        int size = s.size();
        int count = map.size();
        int min_length = s.size()+1 , index = 0 , low = 0 , high = 0;

        while(high < size){
            if(map.find(s[high]) != map.end()){
                count -= (--map[s[high]] == 0);
            }

            while(!count){
                if(min_length > high - low + 1){
                    index= low;
                    min_length = high - low + 1;
                }
                if(map.find(s[low]) != map.end())
                    count +=(++map[s[low]] == 1);
                low++;
            }

            high++;
        }


        return min_length == s.size() + 1 ? "" : s.substr(index , min_length);
    }
};