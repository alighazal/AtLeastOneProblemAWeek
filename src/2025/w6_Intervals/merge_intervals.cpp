class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort( intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        } );

        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++ ){
            if (ans.size() == 0 ){
                ans.emplace_back( intervals[i] );
            }else{
                if ( ans[ ans.size()-1 ][1] >= intervals[i][0] ){
                    ans[ ans.size()-1 ][1] = max ( ans[ ans.size()-1 ][1],  intervals[i][1]); 
                }else{
                    ans.emplace_back( intervals[i] );
                }
            }
        }

        return ans;
    }
};
