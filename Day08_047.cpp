class Solution {
public:
    int minCoins(vector<int> &coins, int sum) {
        // Q. Coin Change – Minimum Coins to Make Sum
        int ans = 0;
        for (int i = coins.size() - 1; i >= 0; --i) {
            ans += sum / coins[i];
            sum %= coins[i];
        }
        return ans;
    }
};
