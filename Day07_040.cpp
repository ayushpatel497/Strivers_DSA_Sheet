class Solution {
public:
    int trap(vector<int>& height) {
        // Q. Trapping Rain Water
        int left = 0, right = height.size()-1; 
        int level = 0, water = 0;
        while (left < right) {
            int lower;
            if(height[left] < height[right]){
                lower = height[left++];
            }
            else{
                lower = height[right--];
            }
            level = max(level, lower);
            water += level - lower;
        }
        return water;
    }
};