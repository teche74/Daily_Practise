class Solution {
public:
    string customSortString(string order, string s) {
        int order_map[26];
        memset(order_map, 0 , 26);

        int ind = 1;

        for(char ch : order){
            order_map[ch - 'a'] = ind++;
        }

        sort(s.begin(),s.end() , [&](char ch1 , char ch2){
                return order_map[ch1 - 'a'] < order_map[ch2 - 'a'];
                
        });

        return s;
    }
};