class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size()-1;
        int low{0}, high{size};

        while(low<high){
            swap(s[low], s[high]);
            low++;
            high--;
        }

    }
};