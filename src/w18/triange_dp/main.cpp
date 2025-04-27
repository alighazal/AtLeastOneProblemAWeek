class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {

        vector<vector<int>> t_dp(t.size() + 1);

        for (int i = 0; i < t.size(); i++ ){
            t_dp[i].resize( t[i].size() );
            fill_n(  t_dp[i].begin(), t_dp[i].size(), 0 );
        }

        t_dp[ t_dp.size() -1 ].resize(  t[ t.size()-1 ].size() + 1 );

        for (int i =0; i< t_dp[ t_dp.size() -1 ].size(); i++){
            t_dp[ t_dp.size() -1 ][i] = (i%2)? 0 : INT_MAX;
        }

        for (int i = t.size()-1; i > -1; i--){
            for (int j = 0; j < t[i].size(); j++ ){
                t_dp[i][j] = min( t_dp[i+1][j],  t_dp[i+1][j+1] ) + t[i][j];
            }
        }

        return t_dp[0][0];
    }
};
