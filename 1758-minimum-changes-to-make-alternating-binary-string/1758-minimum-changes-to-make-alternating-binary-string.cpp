class Solution {
public:
    int minOperations(string s) {
        int minop=0, n=s.length(), f=0;
        for(char c : s){
            if(c-'0' !=f)
              minop++;
            f = !f;
        }       
        return min(minop, n-minop);
    }
};