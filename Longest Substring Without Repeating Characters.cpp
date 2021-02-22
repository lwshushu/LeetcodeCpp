class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left = 0;
        int right = 0;
        int longest = 0;
        vector<int> map (256, -1);
        
        for(int i = 0; i < s.length(); i++)
        {
            if(map[s[i]] >= left) // the char is within the sliding window; it is repeated.
            {
                longest = max(longest, right - left);
                left = map[s[i]] + 1;
            }
            map[s[i]] = i;
            right++;
        }
        
        return max(longest, right - left);
    }
};