class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // approach 1 : set;

        int low = 0 , high = 0 , size = s.size() , res = 0;
        unordered_set<char>st;


        while(high  < size){
            if(st.find(s[high]) == st.end()){
                st.insert(s[high++]);
                res = max(res, high - low);
            }
            else{
                st.erase(s[low++]);
            }
        }
        return res;
    }
};