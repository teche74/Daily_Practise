class Solution {
    private Boolean isPrime(int value){
        if (value <= 1) return false;
        if (value <= 3) return true;
        
        if (value % 2 == 0 || value % 3 == 0) return false;

        for (int i = 5; i * i <= value; i += 6) {
            if (value % i == 0 || value % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    public int sumOfPrimesInRange(int n) {
        int res = 0;

        int revn = Integer.parseInt(new StringBuilder(Integer.toString(n)).reverse().toString());

        for(int i = Math.min(n , revn) ; i <= Math.max(n , revn) ; i++){
            if(isPrime(i)){
                res += i;
            }
        }

        return res;
    }
}