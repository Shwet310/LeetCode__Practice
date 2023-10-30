class Solution {
public:
    static int numberof1s(int n){
        int count = 0;
        while(n){
            count += n&1;
            n = n >> 1;
        }
        return count;
    }
    
   static bool compare(int a, int b){
        int p = numberof1s(a);
        int q = numberof1s(b);
        if(p==q){
            return (a<=b);
        }
        else{
            return (p<q);
        }
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};