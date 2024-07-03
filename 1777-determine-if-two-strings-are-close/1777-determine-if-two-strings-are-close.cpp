class Solution {
public:
    bool closeStrings(string str, string ptr) {
        int n = str.size(), m = ptr.size();

        if(n != m) return false;

        int cnt1[26] , cnt2[26];

        memset(cnt1, 0 , sizeof(cnt1));
        memset(cnt2, 0 ,sizeof(cnt2));

        for(int i =0; i < n ; i++){
            cnt1[str[i] - 'a']++;
            cnt2[ptr[i] - 'a']++;
        }

        // cout<<"str1 : ";

        // for(int i =0; i < 26 ; i++){
        //     cout<<cnt1[i]<<" ";
        // }
        // cout<<endl;

        // cout<<"str2 : ";

        // for(int i =0; i < 26 ; i++){
        //     cout<<cnt2[i]<<" ";
        // }
        // cout<<endl;

        for(int i =0; i < 26; i++){
            if((cnt1[i] == 0 && cnt2[i] != 0) || (cnt2[i] == 0 && cnt1[i] != 0)) return false;
        }


        sort(cnt1 , cnt1 + 26);
        sort(cnt2 , cnt2 + 26);
        
        // cout<<"After sorting >>>"<<endl;

        // cout<<"str1 : ";

        // for(int i =0; i < 26 ; i++){
        //     cout<<cnt1[i]<<" ";
        // }
        // cout<<endl;

        // cout<<"str2 : ";

        // for(int i =0; i < 26 ; i++){
        //     cout<<cnt2[i]<<" ";
        // }
        // cout<<endl;

        for(int i =0 ; i < 26 ; i++){
            if(cnt1[i] != cnt2[i]){
                return false;
            }
        }
        return true;
    }
};