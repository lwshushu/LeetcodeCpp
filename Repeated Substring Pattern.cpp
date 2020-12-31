class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 1)
        {
            return false;
        }
        vector<int> pmt = GeneratePMT(s);
        return pmt[s.size() - 1] != 0 && pmt[s.size() - 1]%(s.size()-pmt[s.size() - 1])==0;
    }
    
    vector<int> GeneratePMT(string& s)
    {
        vector<int> pmt (s.size());
        for(int i = 1; i < s.size(); i++)
        {
            int partialMatchIndex = pmt[i - 1];
            while(partialMatchIndex > 0 && s[i] != s[partialMatchIndex])
            {
                partialMatchIndex = pmt[partialMatchIndex - 1];
            }
            
            if(s[i] == s[partialMatchIndex])
            {
                pmt[i] = partialMatchIndex + 1;
            }
        }
        return pmt;
    }
};