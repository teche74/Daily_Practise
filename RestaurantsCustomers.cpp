#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,char>>input;
    int size;
    int in, out ; 

    while(cin >> size){

        for(int i = 0 ; i < size ; i++){
            cin >> in >> out ;
            input.push_back({in, 'A'});
            input.push_back({out, 'L'});
        }
        
        sort(input.begin() , input.end());
    
        int res = 0 , curr = 0;
    
        for(auto t : input){
            if(t.second == 'A'){
                curr++;
            }
            else{
                curr--;
            }
    
            res = max(res , curr);
        }

        cout<<res<<endl;
    }

    return 0;
}