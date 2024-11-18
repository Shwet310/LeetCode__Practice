class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n,0);
        if (k == 0)
        {
            return result;
        }
        else if (k > 0)
        {
            for(int i = 0;i < n;i++)
            {
                for(int j = i+1; j < (k+i+1);j++)
                    result[i] += code[j % n]; //modulo to cover circular bounds
            }
        }
        else
        {
            k = -k;
            for(int i =0;i < n;i++)
            {
                for(int j = i-k;j < i;j++)
                {
                    result[i] += code[(j+n)%n];
                }
            }
        }
        return result;
    }
};