class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char ,int> map;

        for(char ch : allowed){
            map[ch]++;
        }

        int cnt{0};


        for(auto t : words){
            bool flg = false;
            for(auto ch : t){
                if(map.find(ch) == map.end()){
                    flg = true;
                    break;
                }
            }
            if(!flg) cnt++;
        }
        return cnt;
    }
};