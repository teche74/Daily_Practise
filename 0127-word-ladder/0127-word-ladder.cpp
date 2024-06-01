class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<string>st(wordList.begin() , wordList.end());

        queue<string>q;

        q.push(beginWord);
        int len = 1;

        while(q.size()){
            int size = q.size();

            for(int i =0; i <size; i++){
                string front = q.front();
                q.pop();

                if(front == endWord){
                    return len;
                }
                st.erase(front);

                for(int i =0; i < front.size() ;i++){
                    char ch = front[i];
                    for(int k =0; k < 26 ;k ++){
                        front[i] = 'a' + k;

                        if(st.find(front) != st.end()){
                            q.push(front);
                        }
                    }
                    front[i] = ch;
                }
            }
                len++;
        }
        return 0;
    }
};