class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int countOfDupNum = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i - 1] == nums[i]) countOfDupNum++;
            else nums[i - countOfDupNum] = nums[i];
        }
        
        nums.erase(nums.end() - countOfDupNum, nums.end());
        return nums.size();
    }
};