#include <bits/stdc++.h> 
void solve(string &s, vector<string>& dic, vector<string> &ans, string temp, int start){
    if(start == s.size()){
        temp.pop_back();
        ans.push_back(temp);
        return;
    }

    for(int i = start; i < s.size(); ++i){
        string word = s.substr(start, i - start + 1);
        if(find(dic.begin(), dic.end(), word) != dic.end()){
            solve(s, dic, ans, temp+word + " ", i + 1);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Q. Word Break II
    vector<string> ans;
    solve(s, dictionary, ans, "", 0);
    return ans;
}