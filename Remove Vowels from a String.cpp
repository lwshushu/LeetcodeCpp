class Solution {
public:
    string removeVowels(string s) {
        string str = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                continue;
            }
            str += s[i];
        }
        return str;
    }
};