class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ans=0;
	   for(auto x:nums)
	   ans^=x;                // XORing a number with 0 results in the number itself 
                             // XORing a number with itself results in 0
	   return ans;
    }
};