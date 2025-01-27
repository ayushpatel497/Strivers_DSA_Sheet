//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
	vector<string> AllPossibleStrings(string s){
	   // Q. Power Set
	    // Code here
	    vector<string>ans;
	    for (int index = 1; index < (1 << s.size()); ++index){
            string temp;
            for (int bit = 0; bit < s.size(); bit++){
                if (index & (1 << bit)){
                    temp.push_back(s[bit]);
                }
            } 
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends