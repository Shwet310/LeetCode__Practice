class Solution {
public:
         // Function to solve the problem using dynamic programming
    long long solve(int n, int k, int target){
        // Initializing previous and current arrays to store the number of ways to get the sum 'j'
        vector<long long> prev(target+1,0);
        vector<long long> curr(target+1,0);

        prev[0]=1; // Base case: There's only one way to achieve sum 0

        int mod = 1e9+7; // Modulo value

        // Loop through 'n' dice rolls
        for(int i=1;i<=n;i++){
            // For each number 'j' from 1 to the target
            for(int j=1;j<=target;j++){
                long long ans=0;

                // Calculate the number of ways to achieve sum 'j' with 'i' dice rolls
                for(int x=1;x<=k;x++){
                    if(j-x>=0){
                        ans+=prev[j-x] % mod;
                    }
                }
                curr[j] = ans; // Store the result in the current array
            }
            prev = curr; // Update the previous array for the next iteration
        }
        return prev[target] % mod; // Return the result
    }

    // Function to call the solve function and solve the problem
    int numRollsToTarget(int n, int k, int target) {
        return solve(n, k, target) ; // Call the solve function and return the result
        
    }
};