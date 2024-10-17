class Solution {
public:
    int maximumSwap(int num) {
        string nums = to_string(num);
        int maxdigit = -1; int maxidx = -1;
        int leftidx = -1; int rightidx = -1;
        
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]>maxdigit){
                maxdigit = nums[i];
                maxidx = i;
                continue;
            }
            if(nums[i]<maxdigit){
                leftidx = i;
                rightidx = maxidx;
            }
        }
        if(leftidx == -1) return num;
        swap(nums[leftidx], nums[rightidx]);
        return stoi(nums);
        
    }
};