//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        // Q. N meetings in one room
        int n = start.size();
        vector<vector<int>> meetings(n, vector<int>(2, 0));
        for(int i = 0; i < n; ++i){
            meetings[i][0] = start[i];
            meetings[i][1] = end[i];
        }
        
        sort(meetings.begin(), meetings.end(), cmp);
        
        int count = 0;
        int lastEndTime = -1;
        for (int i = 0; i < n; ++i) {
            if (meetings[i][0] > lastEndTime) {
                count++;
                lastEndTime = meetings[i][1];
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends