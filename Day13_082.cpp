class Solution {
public:
    vector<int> prevSmaller(vector<int> &nums) {
        // Q. Privious Smaller Element
        int n = nums.size();
        vector<int> prevSmall(n, -1);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() >= nums[i]) {
                st.pop();
            }
            prevSmall[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        
        return prevSmall;
    }
};