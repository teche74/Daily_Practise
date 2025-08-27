class Trie{
    vector<Trie*> links;
    bool end = false;
    public:

    Trie() : links(26, nullptr){};


    Trie * GetRef(char ch){
        return links[ch -'a'];
    }

    bool CheckRef(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void CreateRef(char ch , Trie  * node){
        links[ch - 'a'] = node;
    }    

    bool IsEnd(){
        return end;
    }

    void SetEnd(bool val){
        this->end = val;
    }
};

class Solution {
    Trie * root = new Trie();
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //  brute force : chell all possible cases.
        // int size = s.size();

        // function<bool(int)> solve = [&](int index)->bool{
        //     if(index >= size) return true;

        //     for(string str : wordDict){
        //         if(str.size() <= size - index && str[0] == s[index] && str == s.substr(index,str.size())){
        //             // cout<<s.substr(index,str.size())<<endl;
        //             if(solve(index + str.size())) return true;
        //         }
        //     }

        //     return false;
        // };

        // return solve(0);


        for(string str : wordDict){
            Trie * trav = root;
            for(char ch  : str){
                if(!trav->CheckRef(ch)){
                    trav->CreateRef(ch , new Trie());
                }
                trav = trav->GetRef(ch);
            }
            trav->SetEnd(true);
        }

        int memo[301];
        memset(memo , -1 , sizeof(memo));
        function<bool(int , Trie * )> check = [&](int index,  Trie * trav)->bool{
            if(index >= s.size()) return true;

            if(memo[index] != -1) return memo[index];

            for(int i = index; i < s.size(); i++){
                if(!trav->CheckRef(s[i])) break;
                trav = trav->GetRef(s[i]);

                if(trav->IsEnd() && check(i+1 , root)) return memo[index]= true;
            }
            return memo[index] = false;
        };
        return check(0 , root);
    }
};