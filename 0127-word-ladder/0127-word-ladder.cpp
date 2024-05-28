class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int size = wordList.size();

        int len = 1;

        unordered_set<string> dict(wordList.begin(),wordList.end());

        queue<string>pq;

        pq.push(beginWord);

        while(pq.size()){
            int s = pq.size();

            for(int k =0 ;k < s ; k++){
                string frnt = pq.front();
                pq.pop();

                if(frnt == endWord){
                    return len;
                }
                dict.erase(frnt);

                for(int i =0;i < frnt.size() ;i++){
                    char ch = frnt[i];
                    for(int j =0;j < 26 ;j++){
                        frnt[i] = 'a'+ j;

                        if(dict.find(frnt) != dict.end()){
                            pq.push(frnt);
                        }
                    }
                    frnt[i] = ch;
                }
            }
            len++;
        }
        return 0;
    }
};