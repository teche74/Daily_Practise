class Solution {
public:
    int maxDistance(vector<int>& arr) {
        int i =0 , j =arr.size()-1;

        while(arr[j] == arr[i]) j--;

        int len1 = abs(j-i);

        i =0 , j =arr.size()-1;

        while(arr[j] == arr[i]) i++;

        int len2 = abs(j-i);

        return max(len1 , len2);

    }
};