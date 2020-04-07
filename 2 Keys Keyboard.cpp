class Solution {
public:
    int minSteps(int n) 
    {
        int dp[n+1];
        for(int i = 0; i < n+1; i++)
        {
            dp[i] = i;
        }
        dp[1] = 0;
        
        for(int i = 2; i < n+1; i++)
        {
            for(int j = i - 1; j > 0; j--)
            {
                int num = i / j;
                if(i%j == 0)
                {
                    dp[i] = std::min(dp[i], dp[j] + num);
                }
            }
        }
        return dp[n];
    }
};