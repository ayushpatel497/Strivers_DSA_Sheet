#include <bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n) {
    // Q. Maximum of minimum for every window size
    vector<int> ans(n, INT_MIN);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] > a[i]) {
            int index = st.top();
            st.pop();
            if (st.empty()) {
                int range = i;
                ans[range - 1] = max(ans[range - 1], a[index]);
            } else {
                int range = i - st.top() - 1;
                ans[range - 1] = max(ans[range - 1], a[index]);
            }
        }
        st.push(i);
    }
    while (!st.empty()) {
        int index = st.top();
        st.pop();
        if (st.empty()) {
            int range = n;
            ans[range - 1] = max(ans[range - 1], a[index]);
        } else {
            int range = n - st.top() - 1;
            ans[range - 1] = max(ans[range - 1], a[index]);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    return ans;
}