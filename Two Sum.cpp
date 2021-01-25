class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }
        
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++)
        {
            if(map.find(target - nums[i]) != map.end() && map[target-nums[i]] != i)
            {
                ret.push_back(i);
                ret.push_back(map[target-nums[i]]);
                break;
            }
        }
        return ret;
    }
};