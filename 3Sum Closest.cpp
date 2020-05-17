class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        if(nums.size() < 3)
        {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int left = 0, right = 0;
        int result = nums[0] + nums[1] + nums[2];
        int closestDiff = abs(result - target);
        
        for(int i = 0; i < nums.size() - 2; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            left = i + 1;
            right = nums.size()  - 1;
            while(left < right)
            {
                if(left > i + 1 && nums[left] == nums[left - 1])
                {
                    left++;
                    continue;
                }
                if(right < nums.size() - 1 && nums[right] == nums[right + 1]) 
                {
                    right--;
                    continue;
                }
                
                int sum = nums[i] + nums[left] + nums[right];
                
                if(sum == target)
                {
                    return sum;
                }
                
                // calculate the absolute value of difference
                // find the sum of three numbers who has the smallest absolute diff.
                int diff = abs(sum - target);
                if(diff < closestDiff)
                {
                    closestDiff = diff;
                    result = sum;
                }    
                    
                if(sum < target)
                {
                    left++;
                }
                else if(sum > target)
                {
                    right--;
                }
            }
        }
        return result;
    }
};