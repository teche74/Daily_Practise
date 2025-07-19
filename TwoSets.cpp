#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    
    while(cin >> n){
        long long total = 1LL *n * (n +1)/2;
        
        if(total & 1){
            cout<<"NO"<<endl;
            continue;
        }

        long long half = total/2;
        vector<int>first , second;

        for(long long i = n ; i >= 1; i--){
            if(half - i >= 0){
                half -=i;
                first.push_back(i);
            }
            else{
                second.push_back(i);
            }
        }

        cout<<"YES"<<endl;
        cout<<first.size()<<endl;
        for(auto t  : first){
            cout<<t<<" ";
        }
        cout<<endl;
        cout<<second.size()<<endl;
        for(auto t : second){
            cout<<t<<" ";
        }

    }

    return 0;
}