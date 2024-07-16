struct Node {
    Node *links[27]; 
    bool end = false;

    Node() {
        for (int i = 0; i < 27; ++i)
            links[i] = nullptr;
    }

    bool CheckRef(char ch) {
        return links[ch == '/' ? 26 : ch - 'a'] != nullptr;
    }

    void CreateRef(char ch, Node *node) {
        links[ch == '/' ? 26 : ch - 'a'] = node;
    }

    Node *GetRef(char ch) {
        return links[ch == '/' ? 26 : ch - 'a'];
    }

    bool IsEnd() {
        return end;
    }

    void SetEnd(bool val) {
        end = val;
    }
};

class Solution {
public:
    Node * root  = new Node();
    vector<string> removeSubfolders(vector<string>& folder){

        vector<string>res;

        sort(folder.begin(), folder.end(), [](const string & a, const string & b){
            return a.size() < b.size();
        });

        auto find_sub = [&](int index,string str, Node  *temp , string & res){

            for(int i = index ;i < str.size(); i++){
                if(!temp->CheckRef(str[i])) return false;
                temp = temp->GetRef(str[i]);
                res.push_back(str[i]);
                if(temp->IsEnd()&& str[i+1] == '/') return true;
            }

            cout<<"found :"<<res<<endl;

            return false;
        };

        auto insert = [&](string str){
            Node * temp = root;

            for(char ch : str){
                if(!temp->CheckRef(ch)){
                    temp->CreateRef(ch , new Node() );
                }
                temp =temp->GetRef(ch);
            } 
            temp->SetEnd(true);
        };

        

        for(auto t : folder){
            string str = "";
            if(!find_sub(0,t,root,str)){
                insert(t);
                res.emplace_back(t);
            }
        }

        return res;
    }
};