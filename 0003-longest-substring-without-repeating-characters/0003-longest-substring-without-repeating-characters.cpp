class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // approach 1 : set

        // unordered_set<int>st;
        // int low =0 , high = 0 ,  size = s.size() ,res = 0;

        // while(high < size){
        //     if(st.find(s[high]) == st.end()){
        //         st.insert(s[high++]);
        //         res = max(res, high - low);
        //     }
        //     else{
        //         st.erase(s[low++]);
        //     }
        // }

        // return res;






        // approach 2 sliding

        // int map[256];
        // memset(map, 0, sizeof(map));

        // int low = 0 , high = 0 , size = s.size(), res = 0;

        // while(high < size){
        //     map[s[high]]++;
            
        //     while(map[s[high]] > 1){
        //         map[s[low]]--;
        //         low++;
        //     }

        //     res = max(res, high - low+1);

        //     high++;
        // }

        // return res;







        // 3rd approach  :  modified sliding (last occurence).

        int map[256];
        memset(map, -1, sizeof(map));

        int low = 0 , high = 0 , size = s.size(), res = 0;

        while(high  < size){
            low = max(low , map[s[high]] +1);
            res = max(res, high - low+1);
            map[s[high]] = high;
            high++;
        }

        return res;

    }
};