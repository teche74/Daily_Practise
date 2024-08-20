class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        string clean = "";

        int size = s.size();
     
        for(int i = 0 ; i <= size ;i++){
            if(s[i] == ' ' || i == size){
                
                if(!word.empty()){
                    reverse(word.begin(),word.end());
                    clean += word;
                    word.clear();
                    if(i != size) clean.push_back(' '); 
                }

                while(i+1 < size && isspace(s[i+1])) i++; 
            }
            else{
                word.push_back(s[i]);
            }
        }

        if (!clean.empty() && clean.back() == ' ') {
            clean.pop_back();
        }

        reverse(clean.begin(),clean.end());

        return clean;
    }
};
