vector<int> Solution::dNums(vector<int> &A, int B) {
    // Q. Distinct Numbers in Window
    int n = A.size();
    vector<int> answer;
    if(B > n) return answer;
    unordered_map<int, int> mp;

    int left = 0, right = 0;
    mp[A[0]] = 1;
    int count = 1;
    for(right = 1; right < B; ++right){
        mp[A[right]]++;
        if(mp[A[right]] == 1) count++;
    }

    answer.push_back(count);
    while(right < n){
        if(mp[A[left]] == 1) count--;
        mp[A[left]]--;
        left++;
        mp[A[right]]++;
        if(mp[A[right]] == 1) count++;
        right++;
        answer.push_back(count);
    }
    return answer;
}
