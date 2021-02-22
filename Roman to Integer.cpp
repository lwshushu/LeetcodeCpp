class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        int index = 0;
        int result = 0;
        while(index < s.length() - 1)
        {
            if(index + 1 < s.length() && map[s[index + 1]] > map[s[index]])
            {
                result = result + map[s[index + 1]] - map[s[index]];
                index++;
            }
            else
            {
                result += map[s[index]];
            }
            index++;
        }
        return result;
    }
};