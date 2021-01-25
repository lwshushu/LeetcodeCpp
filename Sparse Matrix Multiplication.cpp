class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        vector<vector<int>> ret;
        for(int i = 0; i < A.size(); i++) // iterate A's row
        {
            vector aRow = A[i];
            vector<int> resultRow;
            for(int j = 0; j < B[0].size(); j++) // iterate B's column
            {
                int num = 0;
                for(int k = 0; k < aRow.size(); k++)
                {
                    num += aRow[k] *B[k][j];
                }
                resultRow.push_back(num);
            }
            ret.push_back(resultRow);
        }
        return ret;
    }
};