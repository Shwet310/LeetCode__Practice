class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long result = 0, curWindowSum = 0;
        unordered_set<int> st;
        int i=0, j=0;
        int n = nums.size();
        
        while(j<n){
            while(st.count(nums[j])){
                curWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            curWindowSum += nums[j];
            st.insert(nums[j]);
            
            if(j-i+1 == k){
                result = max(result, curWindowSum);
                
                curWindowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        
        return result;
    }
};