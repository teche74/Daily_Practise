class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());

        queue<string>q;
        q.push(beginWord);
        int level =1;

        while(q.size()){
            int size = q.size();

            for(int i =0; i <size ; i++){
                string ptr = q.front();
                q.pop();
                if(ptr == endWord){
                    return level;
                }
                st.erase(ptr);

                for(int j =0; j < ptr.size() ; j++){
                    char ch = ptr[j];

                    for(char k = 'a' ; k <= 'z' ; k++){
                        ptr[j] = k;

                        if(st.find(ptr) != st.end()){
                            q.push(ptr);
                        }
                    } 

                    ptr[j] = ch;
                }
            }
            level++;
        }
        return 0;
    }
};