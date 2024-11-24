class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int minNum = INT_MAX;
        int cnt = 0;
        long long sum = 0;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                minNum= min(minNum, abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    cnt++;
                    sum += abs(matrix[i][j]);
                }
                else{
                    sum += abs(matrix[i][j]);
                }
            }
        }
        if(cnt%2 == 0) return sum;
        else{
            return sum-2*minNum;
        }
    }
};