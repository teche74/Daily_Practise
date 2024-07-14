class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
       int n=colors.size();
       int length=1,ans=0;
       for(int i=0;i<k;i++)
       {
         colors.push_back(colors[i]);
       }
       for(int i=0;i<n+k-2;i++)
       {
           if(colors[i]!=colors[i+1])
           {
               length++;
               if(length>=k)
               {
                  ans++;
               }
           }
           if(colors[i]==colors[i+1])
           {
               length=1;
           }
       }
       return ans;
    }
};