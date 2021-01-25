class SparseVector {
public:
    SparseVector(vector<int> &nums) 
    {
        // fill the map
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                map[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ret = 0;
        for(auto ele: vec.GetMap())
        {
            if(map.count(ele.first) != 0)
            {
                ret += map[ele.first] * ele.second;
            }
        }
        return ret;
    }
    
    unordered_map<int, int> GetMap()
    {
        return map;
    }
    
private:
    unordered_map<int, int> map; // index of element whose value is not zero, value of the element
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);