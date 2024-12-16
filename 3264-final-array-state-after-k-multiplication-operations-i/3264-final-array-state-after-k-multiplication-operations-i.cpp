class Solution {
public:
    vector<int> getFinalState(vector<int>& v, int k, int m) {
        int n = v.size();
        while(k--) {
            int idx=0,ans=v[0];
            for(int i=1;i<n;i++) {
                if(v[i]<ans) {
                    ans=v[i];
                    idx=i;
                }
            }
            v[idx]=v[idx]*m;
        }
        return v;
    }
};