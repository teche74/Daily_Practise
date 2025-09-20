class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int size = s.size();

        if(s.size() < words.size() * words[0].size()) return {};

        unordered_map<string,int>words_map;
        vector<int>res;

        for(string str : words) words_map[str]++;

        for(int i = 0 ; i < words[0].size() ; i++){
            int low = i ,  high = i;
            unordered_map<string,int>temp_map;
            int word_count = 0;

            while(high + words[0].size() <= size){
                string str = s.substr(high , words[0].size());

                if(words_map.find(str) == words_map.end()){
                    high += words[0].size();
                    low = high;
                    temp_map.clear();
                    word_count = 0;
                }
                else{
                    word_count++;
                    temp_map[str]++;
                    high+=words[0].size();

                    while(temp_map[str] > words_map[str]){
                        string ptr = s.substr(low, words[0].size());
                        temp_map[ptr]--;
                        word_count--;
                        low += words[0].size();
                    }

                    if(word_count == words.size()){
                        res.push_back(low);
                    }
                }
            }
        }

        return res;
    }
};