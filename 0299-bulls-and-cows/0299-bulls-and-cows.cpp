class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0 ,  cows = 0;
        int size = secret.size();

        unordered_map<char,int>map;

        for(char ch : secret){
            map[ch]++;
        }

        for(int i = 0; i  < size ; i++){
            if(guess[i] == secret[i]){
                bulls += (secret[i] == guess[i]);
                if(--map[secret[i]] == 0)
                    map.erase(secret[i]);
            }
        }

        for(int i = 0 ; i < size; i++){
            if(guess[i] != secret[i] && map.find(guess[i]) != map.end()){
                cows += (secret[i] != guess[i]);
                if(--map[guess[i]] == 0)
                    map.erase(guess[i]);
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};