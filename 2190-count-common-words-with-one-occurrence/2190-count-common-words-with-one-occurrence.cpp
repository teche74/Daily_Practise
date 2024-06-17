class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>map1,map2;

        for(auto t : words1){
            map1[t]++;
        }

        for(auto t : words2){
            map2[t]++;
        }

        int count =  0 ;

        for(auto t : map1){
            if(t.second == 1 && map2.find(t.first) != map2.end() && map2[t.first] ==1) count++;
        }

        return count;
    }
};