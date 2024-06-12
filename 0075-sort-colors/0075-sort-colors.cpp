class Solution {
public:
    void sortColors(vector<int>& nums) {
      // for(int i=0; i<nums.size(); i++){
      //     for(int j=i; j<nums.size(); j++){
      //         if(nums[i] != 0 && nums[j]== 0){
      //             swap(nums[i],nums[j]);
      //             i++;
      //         }
      //         if(nums[j]<nums[i]){
      //             swap(nums[i],nums[j]);
      //         }
      //     }
      // }
        
    // Using Dutch National Flag Algo
        
        int low=0, mid=0, high = nums.size()-1;
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};