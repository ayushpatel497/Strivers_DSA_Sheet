class Solution {
public:
    bool isValid(string s) {
        // Q. Valid Parentheses
        stack<char> st;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } 
            else {
                char c = st.top();
                if (st.empty() || (s[i] == ')' && c != '(') || (s[i] == '}' && c != '{') || (s[i] == ']' && c != '[')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};