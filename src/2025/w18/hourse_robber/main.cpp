class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp( nums.size() + 1, 0 );
        for (int i = 0; i < nums.size(); i++){
            int new_val = nums[i];
            if ( i >= 2 ){
                new_val += dp[i-1];
            }
            dp[i+1] = max(new_val , dp[i]);
        }

        return dp[nums.size()];

        
    }
};
