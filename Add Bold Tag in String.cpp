class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) 
    {
    	if(s.size() == 0)
    	{
    		return s;
    	}

    	vector<bool> bold (s.size());
    	for(auto word: dict)
    	{
    		vector<int> pmt = GeneratePMT(word);
    		int partialMatchLength = 0;
    		for(int indexOfString = 0; indexOfString < s.size(); indexOfString++)
    		{
    			if(s[indexOfString] == word[partialMatchLength])
    			{
    				partialMatchLength++;
    			}
    			else
    			{
    				while(partialMatchLength > 0 && s[indexOfString] != word[partialMatchLength])
    				{
    					partialMatchLength = pmt[partialMatchLength - 1];
    				}

    				if(partialMatchLength >= 0 && s[indexOfString] == word[partialMatchLength])
    				{
    					partialMatchLength++;
    				}
    			}

    			if(partialMatchLength == word.size())
    			{
    				fill(bold.begin() + indexOfString - partialMatchLength + 1, bold.begin() + indexOfString + 1, true);
    				partialMatchLength = pmt[partialMatchLength - 1];
    			}
    		}
    	}


		//Tag string s using boolean array bold
        string ret;
        bool state = true;
        for (int i=0; i<s.size(); i++) {
            if (state && bold[i]) {
                ret += "<b>";
                state = false;
            } else if (!state && !bold[i]) {
                ret += "</b>";
                state = true;
            }
            ret.push_back(s[i]);
        }
        if (!state) {
            ret += "</b>";
        }
        return ret; 
    }


    // Generate partial match table
    vector<int> GeneratePMT(string& pattern)
    {
    	vector<int> pmt (pattern.size());

    	for(int i = 1; i < pattern.size(); i++)
    	{
    		int partialMatchIndex = pmt[i - 1];
    		while(partialMatchIndex > 0 && pattern[partialMatchIndex] != pattern[i])
    		{
    			partialMatchIndex = pmt[partialMatchIndex - 1];
    		}

    		if(partialMatchIndex >= 0 && pattern[partialMatchIndex] == pattern[i])
    		{
    			pmt[i] = pmt[partialMatchIndex] + 1;
    		}

    	}
    	return pmt;
    }
};

//kmp:
//partial match table:
//The length of the longest proper prefix in the (sub)pattern that matches a proper suffix in the same (sub)pattern.