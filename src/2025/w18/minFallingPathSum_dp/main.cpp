class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& m) {

        vector<vector<int>>dp( m.size() + 1 );
        for (auto & r : dp){
            r.resize( m.size() );
            fill_n( r.begin(), m.size(), INT_MAX );
        }

        for(int i = 0; i < dp[ dp.size()-1].size(); i++ ){
            dp[ dp.size()-1 ][i] = (i%2)?  INT_MAX: 0;
        }

        for (int i = m.size()-1; i > -1; i--){
            for (int j = 0; j < m.size(); j++){
                int min_val = INT_MAX;
                if (j > 0){
                    min_val = min(min_val, dp[i+1][j-1] );
                }
                if (j < m.size()-1){
                    min_val = min(min_val, dp[i+1][j+1] );
                }
                min_val = min(min_val, dp[i+1][j] );
                dp[i][j] = m[i][j] + min_val;
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < dp[0].size(); i++){
            res = min( res, dp[0][i] );
        }

        return res;

    }
};
