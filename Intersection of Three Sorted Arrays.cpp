class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) 
    {
        vector<int> ret;
        unordered_set<int> set1(arr1.begin(), arr1.end());
        unordered_set<int> set2(arr2.begin(), arr2.end());
        
        for(auto num: arr3)
        {
            if(set1.count(num) && set2.count(num))
            {
                ret.push_back(num);
            }
        }
        return ret;
    }
};