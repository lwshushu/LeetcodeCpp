class Solution {
public:
    string addBinary(string a, string b) 
    {
    	string result = "";
        
        int aIndex = a.size() - 1;
        int bIndex = b.size() - 1;
        int carry = 0;
        int value = 0;

        while(aIndex >= 0 || bIndex >= 0 || carry > 0)
        {
        	value = 0;
        	if(aIndex >= 0)
        	{
        		value = a[aIndex--] - '0';
        	}

        	if(bIndex >= 0)
        	{
        		value += b[bIndex--] - '0';
        	}
        	value += carry;

        	result = char(value % 2 + '0') + result;
        	carry = value / 2;

        }
        return result;
    }
};

// aIndex and bIndex represent the indices of a and b string; 
// carry represent the digit which is transferred from one column of digits 
// to another column of more significant digits. 
// value is the sum of digits of a, b and the carry.

// Addtion only happens when index of a or b is greater or equal to 0 or
// the carry is greater than 0.

// If index of a is greater or equal to 0, do the addition; same for b string.
// Always add the value of carry.
// Result is updated to value % 2 + result;
// and carry becomes value / 2.