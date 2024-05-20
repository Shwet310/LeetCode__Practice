class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        // first create helper function, this fun will help us to calculate when I'm including, when I'm not.
        // the XOR of that array
        return helper(nums, 0, 0);
    }
private:
    int helper(vector<int>& nums, int level, int currentXOR){
        // basse condition
        if(level == nums.size()) return currentXOR;
        // creating include
        int include = helper(nums, level+1, currentXOR ^ nums[level]);
        // creating exclude
        int exclude = helper(nums, level+1, currentXOR);
        return include + exclude;
        
    }
};

