class Solution {
public:
    int longestBalanced(string s) {
        int size = s.size() , res = 0;

        
        for(int i = 0; i < size; i++){
            unordered_map<int,int>map;
            for(int j = i ; j < size ; j++){

                map[s[j]]++;
                int max_count = INT_MIN  , min_count = INT_MAX;

                for(auto t : map){
                    max_count = max(max_count  , t.second);
                    min_count = min(min_count , t.second);
                }

                if(min_count == max_count){
                    res = max(res , j-i+1);
                }
            }
        }

        return res;
    }
};