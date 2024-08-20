struct node{
    node * links[26];
    bool end = false;


    void CreateRef(char ch, node * t){
        links[ch - 'a'] = t;
    }

    bool CheckRef(char ch){
        return links[ch - 'a'] != nullptr;
    }

    node *  GetRef(char ch){
        return links[ch -  'a'];
    }

    bool IsEnd(){
        return end;
    }

    void SetEnd(bool val){
        end = val;
    }
};

class WordDictionary {
    node  *root = new node();
public:
    WordDictionary() {}
    
    void addWord(string word) {
        node  * temp  = root;
        for(char ch : word){
            if(!temp->CheckRef(ch)){
                temp->CreateRef(ch , new node());
            }
            temp = temp->GetRef(ch);
        }
        temp->SetEnd(true);
    }

    int solve(int index, string word, node  *temp){
        if(index >= word.size()){
            return temp->IsEnd();
        }

        char ch  = word[index];
        
        if(ch == '.'){
            for(int i = 0 ;i < 26 ; i++){
                if(temp->links[i] != nullptr && solve(index+1 , word,temp->links[i])) return true;
            }
            return false;
        }
        else{
            if(!temp->CheckRef(ch)) return false;
            temp = temp->GetRef(ch);
        }

        return solve(index+1,word,temp);
    }
    bool search(string word) {
        node * temp = root;

        return solve(0,word,temp);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */