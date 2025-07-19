#include<bits/stdc++.h>
using namespace std;

int main(){
    long long size;

    while(cin >> size){
        vector<int>values(size , 0);

        for(int i = 0 ; i < size ; i++){
            cin >> values[i];
        }

        vector<int>temp = values;
        long long opers = 0;

        for(int i = 1 ; i < size; i++){
            if(temp[i] < temp[i-1]){
                opers += abs(temp[i] - temp[i-1]);
                temp[i] = temp[i-1];        
            }
        }

        cout<<opers<<endl;
    }

    return 0;
}