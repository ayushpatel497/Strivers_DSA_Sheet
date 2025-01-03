class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        // Q. Majority Element II
        int major1 = -1, major2 = -1;
        int count1 = 0, count2 = 0;

        for (auto num : nums) {
            if (num == major1) {
                count1++;
            } 
            else if (num == major2) {
                count2++;
            } 
            else if (count1 == 0) {
                major1 = num;
                count1 = 1;
            } 
            else if (count2 == 0) {
                major2 = num;
                count2 = 1;
            } 
            else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;

        for (auto num : nums) {
            if (num == major1) {
                count1++;
            } 
            else if (num == major2) {
                count2++;
            }
        }

        vector<int> ans;
        int n = nums.size();

        if (count1 > n / 3) {
            ans.push_back(major1);
        }
        if (count2 > n / 3) {
            ans.push_back(major2);
        }

        return ans;
    }
};