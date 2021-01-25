class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(!longShort.count(longUrl))
        {
            string url;
            do{
                url = "";
                for(int i = 0; i < 6; i++)
                {
                    url.push_back(chars[rd() % urlBase.size()]);
                }
            }while(longShort.count(url));
            longShort.insert(pair<string, string>(longUrl, url));
            shortLong.insert(pair<string, string>(url, longUrl));
        }
        return urlBase + longShort[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(shortUrl.size() != urlSize || !shortLong.count(shortUrl.substr(urlBase.size())))
        {
            return "";
        }
        else
        {
            return shortLong[shortUrl.substr(urlBase.size())];
        }
        
    }
private:
    const string urlBase = "http://tinyurl.com/";
    const int urlSize = urlBase.size() + 6;
    const string chars = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<string, string> longShort, shortLong;
    random_device rd;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));