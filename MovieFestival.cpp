#include<bits/stdc++.h>
using namespace std;

int main(){
    int total_movies;

    while(cin >> total_movies){

        vector<pair<int,int>>duration;
        int start, end;

        for(int i = 0; i < total_movies ; i++){
            cin >> start >> end;

            duration.push_back({start,end});
        }

        sort(duration.begin() , duration.end() , [&](pair<int,int> & a, pair<int,int> & b){
            return  a.second < b.second;
        });

        int last_end = 0 , index= 0 , count = 0;

        while(index < duration.size()){
            if(duration[index].first < last_end){
                index++;
                continue;
            }
            else{
                last_end = max(last_end , duration[index].second);
                index++;
                count++;
            }
        }

        cout<<count<<endl;
    }

    return 0;
}