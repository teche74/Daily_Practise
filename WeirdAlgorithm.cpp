#include<bits/stdc++.h>
using namespace std;


int main(){
    long long value;

    while(cin >> value){
        while(value != 1){
            cout<<value<<" ";
            if(value & 1){
                value*=3;
                value++;
            }
            else{
                value/=2;
            }
        }
        cout<<1<<endl;
    }

    return 0;
}