struct Node{
    Node * links[26];
    bool end = false;

    void CreateRef(char ch, Node * node ){
        links[ch - 'a'] = node;
    }

    bool CheckRef(char ch){
        return links[ch - 'a'] != nullptr;
    }

    Node * GetRef(char ch){
        return links[ch - 'a'];
    }

    bool IsEnd(){
        return end == true;
    }

    void SetEnd(bool val){
        end = val;
    }
};

class Solution {
    Node * root ;
public:
    bool SingleChild(Node * temp ){
        int count  =0 ;
        for(int i =0 ;i < 26 ; i++){
            if(temp->links[i] != nullptr){
                count++;

                if(count > 1) return false;
            }
        }
        return true;
    } 

    void SetTrie(vector<string> & strs){
        for(const string  & str : strs){
            Node * temp = root;
            for(char ch : str){
                if(!temp->CheckRef(ch)){
                    temp->CreateRef(ch , new Node());
                }
                temp = temp->GetRef(ch);
            }
            temp->SetEnd(true);
        }
    }

    string longestCommonPrefix(vector<string>& strs) {
        root = new Node();
        SetTrie(strs);

        string pre = "";
        Node * temp =root;

        while(temp && !temp->IsEnd() && SingleChild(temp)){
            for(int i =0 ;i <26 ;i++){
                if(temp->links[i] != nullptr){
                    pre += (i + 'a');
                    temp  =temp->links[i];
                    break;
                }
            }
        }

        return pre;
    }
};