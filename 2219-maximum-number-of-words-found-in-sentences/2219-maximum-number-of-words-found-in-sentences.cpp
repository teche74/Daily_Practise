class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int size = sentences.size();

        int res = 0;

        for(int i =0 ;i  <size ; i++){
            string temp  = sentences[i];

            int words = 0;

            for(int i =0; i < temp.size() ;i++){
                if(temp[i] == ' ' || i == temp.size()-1) words++;
            }

            res = max(res,words);
        }

        return res;
    }
};