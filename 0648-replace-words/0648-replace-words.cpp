struct node{
    node * links[26];
    bool end  = false;

    bool CheckRef(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void CreateRef(char ch , node * t){
        links[ch - 'a'] = t;
    }

    node * GetRef(char ch){
        return links[ch - 'a'];
    }

    bool IsEnd(){
        return end;
    }

    void SetEnd(bool val){
        end= val;
    }
};

class Solution {
    node * root = new node();
public:
    string replaceWords(vector<string>& dict, string sent) {
        auto Init = [&](){
            for(const string  & str : dict){
                node * temp = root;
                for(char ch : str){
                    if(!temp->CheckRef(ch)){
                        temp->CreateRef(ch, new node());
                    }
                    temp = temp->GetRef(ch);
                }
                temp->SetEnd(true);
            }
        };

        auto Get = [&](string str, node * temp){
            string res = "";

            for(int i = 0 ;i <str.size() ; i++){
                if(temp->CheckRef(str[i])){
                    res.push_back(str[i]);
                    temp = temp->GetRef(str[i]);
                    if(temp->IsEnd()) return res;
                }
                else{
                    break;
                }
            }

            return str;
        };

        Init();

        string res = "";

        int low = 0;

        for(int i =0; i < sent.size() ; i++){
            if(sent[i+1] == ' ' || i+1 == sent.size()){
                string temp = sent.substr(low,i - low + 1);
                string ptr = Get(temp,root);
                res += ptr;
                if(i == sent.size()-1) break;
                res.push_back(' ');
                low = i + 2;
            }
        }
        return res;
    }
};