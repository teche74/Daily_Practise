struct node{
    node * links[26];
    bool end = false;

    void CreateRef(char ch , node * n){
        links[ch - 'a'] = n;
    }

    node * GetRef(char ch){
        return links[ch - 'a'];
    }

    bool CheckRef(char ch){
        return links[ch - 'a'] != nullptr;
    }

    bool IsEnd(){
        return end;
    }

    void SetEnd(bool val){
        end = val;
    }
};

class Solution {
    node * root = new node();
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        function<void(void)> init = [&](){
            for(const string  & str : wordDict){
                node * temp = root;
                for(char ch : str){
                    if(!temp->CheckRef(ch)){
                        temp->CreateRef(ch ,  new node());
                    }
                    temp = temp->GetRef(ch);
                }
                temp->SetEnd(true);
            }
        };
        
        init();

        node * temp = root;
        unordered_map<int,bool>dp;

        function<bool(int, node *)> solve = [&](int index, node * temp){
            if(index >= s.size()) return true;

            if(dp.count(index)) return dp[index];

            for(int i = index ; i < s.size(); i++){
                if(!temp->CheckRef(s[i]))break;
                temp = temp->GetRef(s[i]);

                if(temp->IsEnd() && solve(i+1,root)){
                    return dp[index] = true;
                }
            }
            return dp[index] = false;
        };


        return solve(0, temp);
    }
};