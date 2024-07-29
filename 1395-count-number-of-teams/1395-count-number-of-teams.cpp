class Solution {
public:
    int findWays(vector<int>& rating) {
         int n = rating.size();
    
    vector<vector<int>> dp(4, vector<int> (n, 0));
    
    dp[1][0] = 1;
    dp[2][0] = 0;
    dp[3][0] = 0;
    
    for(int i=1; i<n; i++){
        
        int make_two = 0;
        int make_three = 0;
        
        for(int j=0; j<i; j++){
            
            if(rating[i] > rating[j]){
                make_two += dp[1][j];
                make_three += dp[2][j];
            }
        }
        
        dp[1][i] = 1;
        dp[2][i] = make_two;
        dp[3][i] = make_three;
        
    }
    
    
    int total_ways = 0;
    
    for(int i=0; i<n; i++){
        total_ways += dp[3][i];
    }
    
    return total_ways;
    
    }
    int numTeams(vector<int>& rating) {
    
    
    int res = findWays(rating);
    reverse(rating.begin(), rating.end());
    
    res += findWays(rating);
    
    return res;
        
    }
};