#include<bits/stdc++.h>
using namespace std;

void solve(string A , string B , string C , int disks){
    if(!disks){
        return;
    }
    
    solve(A , C , B ,disks-1);
    
    cout<<A<<" "<<C<<endl;

    solve(B , A , C ,disks-1);  
}

int main(){
    int disks;

    
    while(cin >> disks){
        cout<<(1 << disks)- 1<<endl;
        solve("1" , "2" , "3" , disks);
    }

    return 0;
}