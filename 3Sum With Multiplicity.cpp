// We can use unordered_map to store each number and its count.
// We loop key i on all numbers
// We loop key j on all numbers
// Then, we check if k = target - i - j is a valid key in the map
// If not, we continue;
// Otherwise, there are three cases:
// a. i = j = k
//		count of tuple = map[i] * (map[i] - 1) * (map[i] - 2) / (3 * 2 * 1); 
//		We can use combination formula to calculate the number of ways to choose 3 unique indices from map[i] indices 
//		and the reason to use combination formula is because there is one way to order each group of 3 indices in ascending order.
//		This also cover cases when map[i] is smaller than three, which can not form a tuple, so the count will be zero.
// b. i = j != k (we combine two small cases: i = j < k, i < j = k into one)
//		count = map[i] * (map[i] - 1) / (2 * 1) * map[k]
// c. i < j < k (because we loop key i, j on all numbers, there is an interation where j < i which is a case that we have already included in when i < j).
//		count = map[i] * map[j] * map[k]

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        if(A.size() < 3)
        {
            return 0;
        }
        
        long total = 0;
        unordered_map<int, long> map;
        for(auto a: A) map[a]++;
        
        for(auto i_it: map)
        {
            for(auto j_it: map)
            {
                int i = i_it.first, j = j_it.first, k = target - i - j;
                if(!map.count(k)) continue;
                if(i == j && j == k)
                {
                    total += map[i] * (map[i] - 1) * (map[i] - 2) / 6;
                }
                else if(i == j && j != k)
                {
                    total += map[i] * (map[i] - 1) / 2 * map[k];
                }
                else if(i < j && j < k)
                {
                    total += map[i] * map[j] * map[k];
                }
            }
        }
        return total % int(1e9 + 7);
    }
};