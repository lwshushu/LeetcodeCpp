class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int secondSmallestNumIdx, smallestNumIdx;
        
        for(smallestNumIdx = nums.size() - 2; smallestNumIdx >= 0; smallestNumIdx--)
        {
            if(nums[smallestNumIdx] < nums[smallestNumIdx + 1])
            {
                break;
            }
        }
        
        if(smallestNumIdx < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for(secondSmallestNumIdx = nums.size() - 1; secondSmallestNumIdx >= 0; secondSmallestNumIdx--)
            {
                if(nums[secondSmallestNumIdx] > nums[smallestNumIdx])
                {
                    break;
                }
            }
            swap(nums[smallestNumIdx], nums[secondSmallestNumIdx]);
            reverse(nums.begin()+smallestNumIdx+1, nums.end());
        }
    }
};