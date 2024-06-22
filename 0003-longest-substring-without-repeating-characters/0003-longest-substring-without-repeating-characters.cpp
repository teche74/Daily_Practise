class Solution {
public:
    int set_appraoch(string & str){
        set<char>st;

        int low = 0 , high = 0 , size = str.size() , res= 0 ;

        while(high < size){
            if(st.find(str[high]) == st.end()){
                st.insert(str[high++]);
                res = max(res, high - low);
            }
            else{
                st.erase(str[low++]);
            }
        }

        return res;
    }

    int sliding_approach(string & s){
        int low = 0, high = 0 , size = s.size() , res = 0;

        unordered_map<char , int>map;

        while(high < size){
            map[s[high]]++;

            while(map[s[high]] > 1){
                map[s[low++]]--;
            }
            res = max(res, high - low + 1);
            high++;
        }
        return res;
    }

    int frequency_array(string s){
        int freq[128];

        memset(freq, -1, sizeof(freq));

        int low = 0 , high = 0 , size = s.size() , res = 0;

        while(high < size){
            low = max(low, freq[s[high]]+1);
            res = max(res, high - low+1);
            freq[s[high]] = high;
            high++;
        }
        return res;
    }

    int lengthOfLongestSubstring(string s) {
        // int res = set_appraoch(s);
        // int res1 = sliding_approach(s);
        int res3 = frequency_array(s);

        return res3;
    }
};