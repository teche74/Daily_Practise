#include<bits/stdc++.h>
using namespace std;

int main(){
    long long x;
    long long row , col ;

    while(cin >> x){
        while(x--){
            cin >> row >> col;
            long long res = 0;
    
            if(row == 1 && col == 1){
                res = 1;
            }
            else if(row >= col){
                if(row & 1){
                    res = ((row-1) * (row-1) + 1) + (col - 1);
                }
                else{
                    res =  (row*row) - (col - 1);
                }
            }
            else{
                if(col & 1){
                    res = (col * col) - (row - 1);
                }
                else{
                    res =  ((col-1) * (col-1) + 1) + (row - 1);
                }
            }
    
            cout<<res<<endl;
        }
    }
}