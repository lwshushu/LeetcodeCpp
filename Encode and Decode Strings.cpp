class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) 
    {
        string encode = "";

        for(string &s: strs)
        {
            encode += to_string(s.size()) + "#" + s;
        }

        return encode;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) 
    {
        vector<string> ret;
        int pos = 0;

        while(pos < s.size())
        {
            int posPound = s.find_first_of('#', pos);
            int len = stoi(s.substr(pos, posPound - pos));
            int start = posPound + 1;
            ret.push_back(s.substr(start, len));
            pos = start + len;
        }
        return ret;
    }
};