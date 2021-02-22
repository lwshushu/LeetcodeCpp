class Solution {
public:
    int myAtoi(string s) 
    {
        int index = s.find_first_not_of(' ');
        int isPos = 1;
        long ret = 0;
        
        if(index < s.length() && (s[index] == '+' || s[index] == '-'))
        {
            if(s[index] == '-') isPos = -1;
            index++;
        }
        while(index < s.length() && s[index] >= '0' && s[index] <= '9')
        {
            ret = ret * 10 + (s[index] - '0');
            if(ret > INT_MAX) // cannot be >=；otherwise, "-2147483647" will be return INT_MIN.
            {
                if(isPos == -1)
                {
                    return INT_MIN;
                }
                return INT_MAX;
            }
            index++;
        }
        return isPos * ret;
    }
};