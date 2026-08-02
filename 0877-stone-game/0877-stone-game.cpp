class Solution {
private:
    int dfs (int i, int j, vector<int> &piles, vector<vector<int>> &dp) {
        if (i == j) return piles[i];
        if (dp[i][j] != -1) return dp[i][j];
        int left = piles[i] - dfs (i + 1, j, piles, dp);
        int right = piles[j] - dfs (i, j - 1, piles, dp);
        return dp[i][j] = max(left, right);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(0, n - 1, piles, dp) > 0;
    }
};