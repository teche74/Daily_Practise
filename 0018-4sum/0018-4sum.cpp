class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int val) {
        int size = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        for(int i =0; i <size;i++){
            if(i >0 && arr[i] == arr[i-1]) continue;

            for(int j = i+1;j<size ;j++){
                if( j> i+1 && arr[j] == arr[j-1]) continue;

                int k = j+1;
                int l = size-1;

                while(k<l){
                    long  long sum = arr[i];
                    sum+=arr[j];
                    sum+=arr[k];
                    sum+= arr[l];

                    if(sum  == val){
                        vector<int>temp = {arr[i],arr[j],arr[k],arr[l]};
                        res.push_back(temp);

                        k++;
                        l--;

                        while(k<l && arr[k] == arr[k-1]) k++;
                        while(k<l && arr[l] == arr[l+1]) l--;
                    }

                    else if(sum > val){
                        l--;
                    }
                    else{
                        k++;
                    }
                }
            }
        }
        return res;
    }
};