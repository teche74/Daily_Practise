class Solution {
public:
    string removeDuplicateLetters(string s) {
        int size = s.size();

        vector<bool> vis(26,false);
        vector<int> last_seen(26,0);
        stack<char>st;

        for(int i = 0 ; i < size; i++){
            last_seen[s[i] - 'a'] = i;
        }

        for(int i = 0 ;i < size; i++){
            
            if(!vis[s[i] - 'a']){
                while(!st.empty() && last_seen[st.top() - 'a'] > i && st.top() > s[i]){
                    vis[st.top() - 'a'] = false;
                    st.pop();
                }

                st.push(s[i]);

                vis[s[i] - 'a'] = true;
            }
        }

        int size2 = st.size();
        string res = string(size2,'.');

        for (int i = size2 - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};