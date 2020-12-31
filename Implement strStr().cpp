class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
        {
            return 0;
        }
        
        vector<int> pmt = GeneratePMT(needle);
        
        int ret = -1;
        int partialMatchLength = 0;
        for(int i = 0; i < haystack.size(); i++)
        {
            if(haystack[i] == needle[partialMatchLength])
            {
                partialMatchLength++;
            }else
            {
                while(partialMatchLength > 0 && haystack[i] != needle[partialMatchLength])
                {
                    partialMatchLength = pmt[partialMatchLength - 1];
                }
                
                if(haystack[i] == needle[partialMatchLength])
                {
                    partialMatchLength++;
                }
            }
            
            if(partialMatchLength == needle.size())
            {
                ret = i - needle.size() + 1;
                break;
            }
        }
        return ret;
    }
    
    vector<int> GeneratePMT(string& s)
    {
        vector<int> pmt(s.size());
        for(int i = 1; i < s.size(); i++)
        {
            int partialMatchIndex = pmt[i - 1];
            while(partialMatchIndex > 0 && s[i] != s[partialMatchIndex])
            {
                partialMatchIndex = pmt[partialMatchIndex - 1];
            }
            
            if(partialMatchIndex >= 0 && s[i] == s[partialMatchIndex])
            {
                pmt[i] = partialMatchIndex + 1;
            }
        }
        return pmt;
    }
};