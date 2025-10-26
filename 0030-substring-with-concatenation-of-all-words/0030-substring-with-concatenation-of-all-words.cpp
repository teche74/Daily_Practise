class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int size = s.size();
        int total_words = words.size() , word_len = words[0].size();
        vector<int>res;

        if(total_words * word_len > size) return {};

        unordered_map<string,int>freq;

        for(string str : words) freq[str]++;

        for(int i = 0 ; i < word_len ; i++){
            int low = i , high = i , words_count = 0;
            unordered_map<string, int>temp;

            while(high <= size - word_len){
                string str = s.substr(high , word_len);

                if(freq.find(str) == freq.end()){
                    words_count = 0;
                    temp.clear();
                    low = high + word_len;
                } 
                else{
                    temp[str]++;
                    words_count++;

                    while(temp[str] > freq[str]){
                        string ptr = s.substr(low , word_len);

                        temp[ptr]--;
                        words_count--;
                        low += word_len;
                    }

                    if(words_count == total_words){
                        res.push_back(low);
                    }
                }
                high+=word_len;

            }
        }


        return res;
    }
};