class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Q. Largest Rectangle in Histogram
        int maxArea = 0;
        int n = heights.size();
        stack<int> st;
        for(int i = 0; i <=n; ++i){
            int currHeight = i == n ? 0 : heights[i];
            while(!st.empty() && currHeight < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};