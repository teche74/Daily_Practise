class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        queue<string>pq;

        pq.push(beginWord);

        int len =1;

        while(pq.size()){
            int n = pq.size();

            for(int i =0; i <n ; i++){
                string frnt = pq.front();
                pq.pop();

                if(frnt == endWord) return len;
                dict.erase(frnt);

                for(int j =0 ;j < frnt.size() ;j++){
                    char ch = frnt[j];

                    for(int k =0; k< 26 ; k++){
                        frnt[j] = 'a' + k;

                        if(dict.find(frnt) != dict.end()){
                            pq.push(frnt);
                        }
                    }
                    frnt[j] = ch;
                }
            }
            len++;
        }
        return 0;
    }
};