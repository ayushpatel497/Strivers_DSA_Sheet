class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // Q. Count Subarrays with XOR k
        unordered_map<long, long> um;
        um[0] = 1;
        long currXOR = 0;
        long ans = 0;
        for(int i = 0; i < arr.size(); ++i){
            currXOR ^= arr[i];
            if(um.count(currXOR ^ k)){
                ans += um[currXOR ^ k];
            }
            um[currXOR]++;
        }
        return ans;
    }
};