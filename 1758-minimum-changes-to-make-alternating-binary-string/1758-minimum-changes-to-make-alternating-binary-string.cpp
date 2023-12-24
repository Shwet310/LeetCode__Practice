class Solution {
public:
    int minOperations(string s) {
        int minop=0, f=0;
        for(char c : s){
            if(c-'0' !=f)
              minop++;
            f = !f;
        }       
        return min(minop, (int)s.size()-minop);
    }
};