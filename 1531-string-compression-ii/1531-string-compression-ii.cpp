class Solution {
int n;
    
private:
    int f(int idx, char prev, int curCharFreqCount, string &s, int k, int dp[][27][11][101])
    {
        if(k < 0) return 1e9;
        
        if(idx >= n)
            return 0;
        
        // if curCharFreqCount, consider it as 10, because, until 10 .. 99, string length will be 2, 
        if(curCharFreqCount >= 10)
            curCharFreqCount = 10;
        
        if(dp[idx][prev - 'a'][curCharFreqCount][k] != -1)
            return dp[idx][prev - 'a'][curCharFreqCount][k];
        
        
        int res = 1e9;
        
        /*
        3 cases:
        case 1: We will delete our current character if K is available, so our string length will be minimum.
        case 2: If cur char is not same as prev, our res will be increased by 1 and curCharFreqCount will be 1
        case 3: If cur char is same as prev char, we need to merge it and increase our count
                case 3.1: If curCharFreqCount is either 1 or more than 9, our res will be increased by 1
                case 3.2: Else, we just need to increase curCharFreqCount.
        */
        
        // case 1
        res = min(res, f(idx+1, prev, curCharFreqCount, s, k-1, dp));
        
        // case 2
        if(s[idx] != prev)
            res = min(res, 1 + f(idx + 1, s[idx], 1, s, k, dp));
        
        // case 3
        else{
            
            // case 3.1
            if(curCharFreqCount == 1 || curCharFreqCount == 9)
            {
                res = min(res, 1 + f(idx + 1, prev, (curCharFreqCount + 1), s, k, dp));
            }
            
            // case 3.2
            else{
                res = min(res, f(idx + 1, prev, curCharFreqCount + 1, s, k, dp));
            }
        }
        
        return dp[idx][prev - 'a'][curCharFreqCount][k] = res;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        
        // 4 states -> [idx][prev_char][freq_count][k]
        n = s.size();
        
        if(n == k) return 0;
        
        bool allSame = true;
            
        // Base case: check for all char are same
        for(int i = 1; i < n; i++)
        {
            if(s[i] != s[i-1])
            {
                allSame = false;
                break;
            }
        }

        if(allSame)
        {
            /*
            log10(n) + 1 => used to count the number of digits 
            eg: 100 => log10(100) + 1 = 2 + 1 = 3 (number of digits in 100)
            */
            
            // we can remove k characters from n
            n  -= k;
            
            // if n is 1, we don't need to write 1 as per question
            if(n == 1) 
                return 1;
            
            // we need to add +1 for considering cur char + (number of digits in n)
            return log10(n) + 1 + 1;            
        }
        
        
        int dp[n+1][27][11][101];
        
        memset(dp, -1, sizeof(dp));
        
        return f(0, 'z' + 1, 0, s, k, dp);
        
    }
};