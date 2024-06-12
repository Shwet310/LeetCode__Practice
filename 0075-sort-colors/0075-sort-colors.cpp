class Solution {
public:
    void sortColors(vector<int>& nums) {
      for(int i=0; i<nums.size(); i++){
          for(int j=i; j<nums.size(); j++){
              if(nums[i] != 0 && nums[j]== 0){
                  swap(nums[i],nums[j]);
                  i++;
              }
              if(nums[j]<nums[i]){
                  swap(nums[i],nums[j]);
              }
          }
      }
    }
};