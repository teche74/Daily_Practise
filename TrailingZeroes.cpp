#include<bits/stdc++.h>
using namespace std;

int main(){
    long long num ;

    while(cin >> num){
        long long count = 0;

        for(int i = 5; num / i >= 1 ; i = i*5){
            count += num / i;
        }

        cout<<count<<endl;
    }
    return 0;
}