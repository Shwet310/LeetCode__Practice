class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int i,co=0,sum1=0,ans=0;
        for(i=0;i<arr.size();i++)
        {
            sum1+=i;
            co+=arr[i];
            if(sum1==co)
                ans++;
        }
        return ans;
    }
};