struct node{
    node * links[4];
    bool end = false;

    int charToIndex(char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
            default: return -1;
        }
    }

    void CreateRef(char gene , node * node){
        links[charToIndex(gene)] = node;
    }

    bool CheckRef(char gene){
        return links[charToIndex(gene)] != nullptr;
    }

    node * GetRef(char gene){
        return links[charToIndex(gene)];
    }


    bool isEnd(){
        return end;
    }

    void SetEnd(bool val){
        end = val;
    }

    bool search(const string& word) {
        node* temp = this;
        for (char c : word) {
            int index = charToIndex(c);
            if (!temp->links[index]) {
                return false;
            }
            temp = temp->links[index];
        }
        return temp->isEnd();
    }
    
    void remove(const string& word) {
        node* temp = this;
        for (char c : word) {
            int index = charToIndex(c);
            if (!temp->links[index]) {
                return;
            }
            temp = temp->links[index];
        }
        temp->SetEnd(false);
    }
};

class Solution {
public:
    node * root = new node();

    int minMutation(string startGene, string endGene, vector<string>& bank) {

        auto  Init = [&](){
            for(const string  & str : bank){
                node * temp = root;

                for(char ch : str){
                    if(!temp->CheckRef(ch)){
                        temp->CreateRef(ch , new node());
                    }
                    temp = temp->GetRef(ch);
                }
                temp->SetEnd(true);
            }
        };

        Init();
        
        if (!root->search(endGene)) {
            return -1; 
        }
        
        vector<char> chars = {'A', 'C', 'G', 'T'};
        queue<pair<string, int>> vis;
        vis.push({startGene, 0});
        
        while (!vis.empty()) {
            auto [currentGene, currentLevel] = vis.front();
            vis.pop();
            
            if (currentGene == endGene) {
                return currentLevel;
            }
            
            for (int i = 0; i < currentGene.size(); ++i) {
                char originalChar = currentGene[i];
                
                for (char ch : chars) {
                    if (ch == originalChar) continue;
                    
                    currentGene[i] = ch;
                    
                    if (root->search(currentGene)) {
                        vis.push({currentGene, currentLevel + 1});
                        root->remove(currentGene);  
                    }
                }
                
                currentGene[i] = originalChar;  
            }
        }
        
        return -1;      
    }
};