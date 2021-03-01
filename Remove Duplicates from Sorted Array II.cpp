class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int countOfDupNum = 0;
        bool mayHaveSecondDupNum = true;
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i - 1] == nums[i]) 
            {
                if(mayHaveSecondDupNum)
                {
                    nums[i - countOfDupNum] = nums[i];
                }
                else
                {
                    countOfDupNum++;
                }
                mayHaveSecondDupNum = false;
            }
            else
            {
                nums[i - countOfDupNum] = nums[i];
                mayHaveSecondDupNum = true;
            }
        }
        
        nums.erase(nums.end() - countOfDupNum, nums.end());
        return nums.size();
    }
};