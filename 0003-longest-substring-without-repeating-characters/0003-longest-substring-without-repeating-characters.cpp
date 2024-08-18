class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // approach 1 : set;

        // int low = 0 , high = 0 , size = s.size() , res = 0;
        // unordered_set<char>st;


        // while(high  < size){
        //     if(st.find(s[high]) == st.end()){
        //         st.insert(s[high++]);
        //         res = max(res, high - low);
        //     }
        //     else{
        //         st.erase(s[low++]);
        //     }
        // }
        // return res;


        // unordereded map  approach 2

        int low = 0 , high = 0 , size = s.size() , res = 0 ;
        unordered_map<char,int>map;

        while(high < size){
            map[s[high]]++;

            while(map[s[high]] > 1){
                map[s[low]]--;
                low++;
            }

            res = max(res, high - low+1);
            high++;
        } 

        return res;
    }
};