#include <bits/stdc++.h>
using namespace std;


int main()
{
    int size;

    while(cin >> size){
        long long val = 1;
        
        while(size--){
            val*=2;
            val %= 1000000007;
        }
        cout<<val<<endl;
    }

    return 0;
}