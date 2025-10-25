class Solution {
public:
    int totalMoney(int n) {
        int days = 0 , sum = 0, alpha = 0;

        while(n > 0){
            days = n >= 7 ? 7 : n;
            sum += ((days) * (days +1))/2;
            sum += (days * alpha);
            alpha++;
            n-=days;
            // cout<<alpha+1 <<" week : "<<sum<<". days  left : "<<n<<endl;
        }

        return sum;
    }
};