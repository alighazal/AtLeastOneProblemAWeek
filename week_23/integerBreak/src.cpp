class Solution {
public:
    unordered_map<int, int> dp;
    int dfs(int n, int k){
        if (n == 0){
            if ( k < 2 ) {
                return -1;
            }
            else {
                return 1;
            }
        }
        if (dp.find(n) != dp.end()) return dp[n];
        int res = INT_MIN;
        for (int i = 1; i <= n; i++){
            res = max(res, i * dfs(n-i, k+1) );
        }

        dp[n] = res;
        return res;
    }

    int integerBreak(int n) {
        return dfs(n, 0);
    }
};
