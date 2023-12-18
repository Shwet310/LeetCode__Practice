class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
         int a = INT_MIN, b = INT_MIN, c = INT_MAX, d = INT_MAX;
    for(int& i : nums){
        if(i > a || i > b){
            b = max(b, a);
            a = i;
        }
        if(i < c || i < d){
            d = min(d, c);
            c = i;
        }
    }
    
    return (a*b)-(c*d);    
       
    }
};