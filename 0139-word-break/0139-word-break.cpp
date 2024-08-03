struct Node{
    Node * links[26];
    bool end =false;


    void CreateRef(char ch, Node * n){
        links[ch - 'a'] = n;
    } 

    bool CheckRef(char ch){
        return links[ch - 'a'];
    }

    Node * GetRef(char ch){
        return links[ch - 'a'];
    }

    bool CheckEnd(){
        return end;
    }

    void SetEnd(bool val){
        end = val;
    }
};

class Solution {
public:
    unordered_map<int,bool>map;
    Node * root = new Node();

    bool solve(int index, const string & str, Node  *temp ){
        if(index == str.size()) return true;

        if(map.count(index))return map[index];

        for(int i = index ;i < str.size() ; i++){
            if(!temp->CheckRef(str[i])){
                break;
            }
            temp = temp->GetRef(str[i]);
            if(temp->CheckEnd() && solve(i+1,str,root)){
                map[index] = true;
                return true;
            }
        }
        return map[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(string  &str : wordDict){
            Node * temp = root;

            for(char ch : str){
                if(!temp->CheckRef(ch)){
                    temp->CreateRef(ch , new Node());
                }
                temp = temp->GetRef(ch);
            }
            temp->SetEnd(true);
        }   

        Node *temp = root;
        return solve( 0, s, temp);
    }
};