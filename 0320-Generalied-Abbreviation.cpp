#include<bits/stdc++.h>
using namespace std;

vector<string> generateAbbreviations(string word){
    int size = word.size();
    
    vector<string>res;
    string temp = "";
    
    function<void(int)> call = [&](int index){
        if(index >= size){
            res.push_back(temp);
            return;
        }
        
        temp.push_back(word[index]);
        call(index+1);
        temp.pop_back();
        
        if(temp.size() && !isdigit(temp.back()) || temp.empty()){
            for(int i = index; i < size;i++){
                temp += to_string(i - index + 1);
                call(i+1);
                temp.pop_back();
            }
        }
    };
    
    call(0);
    return res;
}


int main(){
    string input;
    while(cin >> input){
        vector<string> res = generateAbbreviations(input);
        for(auto t : res){
            cout<<t<<endl;
        }
        cout<<endl;
    }
    return 0;
}


