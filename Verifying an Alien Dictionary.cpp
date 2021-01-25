class Solution {
public:
    
    int CompareAlienStr(string s1, string s2, vector<int>& table)
    {
        int i = 0;
        while(i < s1.length() && i < s2.length())
        {
            if(table[s1[i] - 'a'] < table[s2[i] - 'a'])
            {
                return 1;
            }
            else if(table[s1[i] - 'a'] > table[s2[i] - 'a'])
            {
                return -1;
            }
            i++;
        }
        
        if(s1.size() == s2.size()) return 0;
        else if(i >= s1.size()) return 1;
        else return -1;
    }
    
    bool isAlienSorted(vector<string>& words, string order) 
    {
        //First, we want to have a hash table to record the order of the alphabet
        //Then, we can use the it to compare each char of two 
        //neighboring strings.
        
        //Key of the table is the letter
        //Value is its order
        vector<int> table(26);
        for(int i = 0; i < 26; i++)
        {
            table[order[i] - 'a'] = i;
        }
        
        for(int i = 0; i < words.size() - 1; i++)
        {
            if(CompareAlienStr(words[i], words[i+1], table) == -1)
            {
                return false;
            }
        }
        return true;
    }
};