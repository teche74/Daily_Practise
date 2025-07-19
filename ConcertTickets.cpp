#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m;

    while(cin >> n >> m){
        vector<int>prices(n, 0), customer_max_price(m, 0);

        for(int i = 0 ; i < n ; i++){
            cin >> prices[i];
        }

        for(int i = 0 ; i < m ; i++){
            cin >> customer_max_price[i];
        }

        multiset<int>st(prices.begin(), prices.end());

        for(auto t : customer_max_price){
            auto it = st.upper_bound(t); 
            
            if(it != st.begin()){
                --it;
                cout<<*it<<endl;
                st.erase(it);
            }
            else{
                cout<<"-1"<<endl;
            }
        }
    }
    return 0;
}