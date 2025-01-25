class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Q. Maximum Product Subarray
        int numsSize = nums.size();
        int productPrefix = 1, productSuffix = 1;
        int answer = INT_MIN;
        for (int index = 0; index < numsSize; ++index) {
            if (productPrefix == 0) productPrefix = 1;
            if (productSuffix == 0) productSuffix = 1;
            productPrefix *= nums[index];
            productSuffix *= nums[numsSize - index - 1];
            answer = max(answer, max(productPrefix, productSuffix));
        }
        return answer;
    }
};