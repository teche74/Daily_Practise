class Solution {
public:
    unordered_map<string , string>map;

    string generate_base(int len){
        string dict = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~";

        string result = "";

        srand(static_cast<unsigned int>(time(0)));

        for (int i = 0; i < len; i++) {
            result += dict[rand() % dict.length()];
        }

        return result;
    }


    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string base = generate_base(6);

        map[base] = longUrl;

        return base; 
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));