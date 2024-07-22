class Solution {
    unordered_map<string, string> url_map;
    string dict = "123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTEUVWXYZ";
    int len = 6;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {

        function<string(void)> generate = [&](){
            string code = "";

            for(int i = 0 ; i < len ; i++){
                code.push_back(dict[rand() % dict.size()]);
            }

            return code;
        };

        string encoded_url = "https://tinyurl.com/";

        string temp ="";

        do{
            temp = generate();
        }while(url_map.find(encoded_url) != url_map.end());

        encoded_url += temp;

        url_map[encoded_url] = longUrl;

        return encoded_url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return url_map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));