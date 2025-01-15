class Solution {
public:
    int myAtoi(string s) {
        // Q. String to Integer (atoi)
        double ans = 0;
        int i = 0;
        while(s[i] == ' ')
            i++;
        bool positive = s[i] == '+';
        bool negative = s[i] == '-';
        positive ? i++ : i;
        negative ? i++ : i;
        while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
            ans = ans * 10 + (s[i] - '0');
            i++;
        }
        ans = negative ? -ans : ans;
        ans = (ans > INT_MAX) ? INT_MAX : ans;
        ans = (ans < INT_MIN) ? INT_MIN : ans;
        return int(ans);
    }
};