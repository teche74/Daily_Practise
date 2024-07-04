class Solution {
public:
    int balancedString(string s) {
        int size = s.size();

        unordered_map<char,int>map;

        for(char ch : s){
            map[ch]++;
        }

        int low = 0 , high = 0 , res=  size, limit = size/4;

        if (map['Q'] == limit && map['W'] == limit && map['E'] == limit && map['R'] == limit) {
            return 0;
        }

        while(high < size){
            map[s[high]]--;

            while(low < size && map['Q'] <= limit  && map['W'] <= limit && map['E'] <= limit && map['R'] <= limit){
                res =min(res, high - low +1);
                map[s[low]]++;
                low++;
            }

            high++;
        }

        return res;
    }
};