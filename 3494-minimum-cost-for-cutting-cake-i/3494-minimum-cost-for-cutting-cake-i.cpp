class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        //  m  cross n he final 1 cross 1 chahiye cost di he minimum chaiye , dimag me kya ayya greedy sort na bss khattam 

        long long i = 0 , j = 0 , res = 0 , v_peices = 1 , h_peices = 1;
        // v peices or h peices 1 kiya ?  ( pura utha to ek hi peice hoga horizontal dekh ya vertical dekh.


        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        // sort ulta krte na me bolta minimum chahiye to simple chlte high  to low cost .

        // ab isko jo mene upar kha vo ajjeb lga hoga jab minimum chahiye to low to high jana chahiye high to low kyon ? hena chlo samjhte phle cost multiplication principle ko 

        // me khta me sabse mhnge phle uthaunga taki baad me mere number of peices jyada ho jayen tab me koi expensive cut na dun . (1 peice pe 50 dena bhot shi he 18 peices pe 10 dene se)

        while( i < horizontalCut.size() && j < verticalCut.size() ){
            if( horizontalCut[i] >= verticalCut[j] ){
                res += horizontalCut[i] * v_peices;
                h_peices++;
                i++;
            }
            else{
                res += verticalCut[j] * h_peices;
                v_peices++;
                j++;
            }
        }

        // ab bche hue honge last me unko theekane lgado khattam .

         while (i < horizontalCut.size()) {
            res += horizontalCut[i] * v_peices;
            i++;
        }

        while (j < verticalCut.size()) {
            res += verticalCut[j] * h_peices;
            j++;
        }

        return res;

    }
};