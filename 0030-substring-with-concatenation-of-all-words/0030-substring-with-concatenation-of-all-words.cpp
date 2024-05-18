class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int size = s.size();

        int total_words = words.size(), word_len = words[0].size();

        int new_size = total_words * word_len;

        if(new_size > size ) return {};

        unordered_map<string,int>map;
        vector<int>res;

        for(const string & str : words){
            map[str]++;
        }

        for(int i =0 ; i < word_len ;i++){
            int left = i;
            unordered_map<string,int>temp_count;
            int count = 0;

            for(int j =i ; j<=size - word_len ; j+=word_len){
                string temp = s.substr(j,word_len);

                if(map.find(temp) == map.end()){
                    count  =0;
                    temp_count.clear();
                    left = j+word_len;
                }
                else{
                    count++;
                    temp_count[temp]++;

                    while(temp_count[temp] > map[temp]){
                        string ptr = s.substr(left, word_len);
                        temp_count[ptr]--;
                        count--;
                        left+=word_len;
                    }

                    if(count == total_words){
                        res.emplace_back(left);
                    }
                }
            }
        }
        return res;
    }
};