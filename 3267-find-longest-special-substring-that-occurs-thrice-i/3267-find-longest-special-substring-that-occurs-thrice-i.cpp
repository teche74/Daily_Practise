class Solution {
public:
    int solve(const string & s , int len){
        int low =0 , high = 0 , size = s.size();
        unordered_map<char,int>map;
        unordered_map<string,int>counter;
        int freq=0 ;

        while(high < size){
            map[s[high]]++;


            while(high - low + 1 > len || map.size() > 1){
                map[s[low]]--;
                if(map[s[low]] == 0) map.erase(s[low]);
                low++;
            }

            if(high - low + 1 == len && map.size() == 1){
                string t = s.substr(low, len);
                counter[t]++;
                freq = max(freq,counter[t]);
            }
            high++;
        }

        return freq >= 3  ? len : -1;
    }
    int maximumLength(string s) {
        int size =  s.size();
        int uni = 0;
        // unordered_map<char,int>map;

        // for(char ch  :s){
        //     map[ch]++;
        // }

        // if(map.size() == size) return -1;

        int res = -1;
        for(int i = 1; i < size; i++){
            res = max(res,solve(s,i));
        }

        return res;
    }
};