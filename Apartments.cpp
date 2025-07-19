#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n , m ,k ;

    while(cin >> n >> m >> k){
        vector<long long>desired(n, 0), available(m,0);

        for(long long i = 0 ; i < n; i++){
            cin >> desired[i];
        }

        for(long long i = 0 ;i < m; i++){
            cin >>available[i];
        }

        sort(desired.begin(), desired.end());
        sort(available.begin(), available.end());

        long long desired_index = 0 , available_index = 0, count = 0;

        while(available_index < m && desired_index < n){
            if(desired[desired_index] < available[available_index] - k){
                desired_index++;
            }
            else if(desired[desired_index] > available[available_index] + k){
                available_index++;
            }
            else{
                count++;
                desired_index++;
                available_index++;
            }
        }

        cout<<count<<endl;

    }

    return 0;
}