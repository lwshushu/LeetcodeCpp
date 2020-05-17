class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int number = 0;
        
        while(n > 0)
        {
            n = n & (n-1);
            number++;
        }
        return number;
    }
};