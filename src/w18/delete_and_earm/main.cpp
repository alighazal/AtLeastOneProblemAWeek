class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {

        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++ ){
            m[nums[i]] ++;
        }
        vector<int> nums_without_duplicates;
        for(auto & p : m ){
            nums_without_duplicates.push_back( p.first );
        }
        sort( nums_without_duplicates.begin(), nums_without_duplicates.end() );
        vector<int> dp(nums_without_duplicates.size()+1, 0);
        for (int i = 0; i < nums_without_duplicates.size(); i++ ){
            if ( i == 0 ){
                dp[1] = nums_without_duplicates[i] * m[ nums_without_duplicates[i] ];
            }else{
                if ( nums_without_duplicates[i] == nums_without_duplicates[i-1] + 1 ){
                    dp[i+1] = max(  dp[i],  nums_without_duplicates[i] * m[ nums_without_duplicates[i] ] + dp[i-1] );
                }else{
                    dp[i+1] = dp[i] + nums_without_duplicates[i] * m[ nums_without_duplicates[i] ];
                }
            }
        }
        return dp[nums_without_duplicates.size()];
        
    }
};
