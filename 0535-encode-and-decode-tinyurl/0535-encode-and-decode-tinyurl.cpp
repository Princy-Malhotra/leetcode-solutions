class Solution {
public:
    int sr_no=0;
    unordered_map<string, string>mp;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string encoded_str = "http://tinyurl.com/"+ to_string(sr_no);
        sr_no++;
        mp[encoded_str] = longUrl;
        return encoded_str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));