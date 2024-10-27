class Solution {
public:
    int countSquares(vector<vector<int>>& M) {
        int res = 0;
        for (int i = 0; i < M.size(); ++i)
            for (int j = 0; j < M[0].size(); res += M[i][j++])
                if (M[i][j] && i && j)
                    M[i][j] += min({M[i - 1][j - 1], M[i - 1][j], M[i][j - 1]});
        return res;
    }
};