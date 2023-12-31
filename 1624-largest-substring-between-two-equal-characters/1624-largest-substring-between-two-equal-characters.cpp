class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        int end = s.length();
        for(int i =0; i<end; i++){
            for(int j = i+1; j<end; j++){
                if(s[i] == s[j])
                    ans = max(ans, j-i-1);
                    }
        }
        return ans;
    }
};