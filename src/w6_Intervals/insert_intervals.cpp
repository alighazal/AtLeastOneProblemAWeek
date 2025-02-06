class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        // insert
        bool inserted = false;
        for (int i = 0; i < intervals.size(); i++){
            if ( newInterval[0] <= intervals[i][0]  ){
                intervals.insert(  intervals.begin() + i,  newInterval  );
                inserted = true;
                break;
            }
        }

        if (!inserted){
            intervals.push_back(newInterval);
            inserted = true;
        }

        // merge
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
