class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        unordered_map<string, vector<string>> map;
        
        for(string s: strs)
        {
            // Remember to re-initialize a new string;
            string str = s;
            sort(str.begin(), str.end());
            map[str].push_back(s);
        }
        
        for(auto m: map)
        {
            groups.push_back(m.second);
        }
        
        return groups;
    }
};