class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Q. Sort Colors
        int i = 0;
        int j = nums.size() - 1;
        int k = 0;
        while(k <= j){
            if(nums[k] == 0){
                swap(nums[i],nums[k]);
                i++;
                k++;
            }
            else if(nums[k] == 2){
                swap(nums[j],nums[k]);
                j--;
            }
            else{
                k++;
            }
        }
    }
};