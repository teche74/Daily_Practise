class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // dekho miss apko kuch nhi sochna permutation mtlv arrangement hota he words ka 

        //  eg = rashmi : mirash

        // ab dekho ab hme pta hi ki bas check krne he fix size window me ki same character same frequency ke sath aye hen ki ni.


        // unordered map se me sare character or unki frequency daldo (taki hme pta chll ske konse character lene hen or kitne lene he ).
        unordered_map<char,int>map;

        for(char ch  : s1){
            map[ch]++;
        }

        // ab hm dekhenge ki total kitne unique characters chahiye.
        int count = map.size();

        
        // sliding window chlayen or check krte hen dekhte ki esa sequence present he ki ni
        int low= 0 , high =  0 , size = s2.size();

        while(high < size){
            // check kro ki jis character pr hum hen vo hme chahiye ki ni.
            if(map.find(s2[high])!= map.end()){
            // har character milne pr miss ap  uski frequency kam kroge.
                map[s2[high]]--;

                // agr sare occuence mil jaye ek chracter ke 
                // eg - pplea liya ab dekho isme high update hoga to jese hi dono pp ajayenge tak me remaining chracters 4 se 3 hoo jayenge , i hope samjh agya ho 
                count-=(map[s2[high]] == 0);   
            }

            //  count  0 hogya mtlv hme sare chracters mil chuke hen.
            // lekin ab apko yea bhi dekhna ki jo window ke size me mujhe sare chracter mile kya vo actual length ke brabr hen ki ni .
            while(count == 0){

                // ye rhi vo brabr check krne ki condition
                if(high - low + 1 == s1.size()) return true;

                //  agr manlo nhi he to  app window shrink kroge , shrink krte samy apko ye dhyan dena he ki jis element pe me operation perform krungi vo mere string ka part hona chechiye vrna mujhe usse koi mtlv nhi.
                if(map.find(s2[low]) != map.end()){
                    // aapne usko map se htaya 
                    map[s2[low]]++;
                    // agr vo word ek bar that tohtate jitne dhundhne he usme plus 1 krdo
                    count += (map[s2[low]] ==1);
                }

                // shrink krre ho windo ko .
                low++;
            }

            high++;
        }

        return false;

    }
};