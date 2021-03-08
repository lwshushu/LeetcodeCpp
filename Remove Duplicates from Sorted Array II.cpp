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



//Solution2:
//1. We compare n with nums[insertLoc - 2].
// If the n is greater than the num whose index is two smaller than the index where the n might be placed,
// then n should be placed there.
//2. The difference between solution 1 and s2 is s2 records the location that the new number should go.
// While s1 records how many duplicate numbers there are, which helps us to determine the location.
//Solution 2 is easier than s1 if we can understand the fact 1.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertLoc = 0;
        
        for(int n: nums)
        {
            if(insertLoc < 2 || n > nums[insertLoc - 2])
            {
                nums[insertLoc++] = n;
            }
        }
        
        nums.erase(nums.begin() + insertLoc, nums.end());
        return insertLoc;
    }
};