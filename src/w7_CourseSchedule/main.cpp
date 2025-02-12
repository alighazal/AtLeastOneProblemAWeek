class Solution {
public:

    bool dfs( unordered_map< int, vector<int>> & p_m, set<int>& visited,  int c ){
        if ( visited.find( c ) != visited.end() ) return false;
        if ( p_m[c].size() == 0 ) return true;

        visited.insert( c );

        for (auto & pre : p_m[c]){
            bool res = dfs(  p_m, visited, pre );
            if (res == false){
                return false;
            }
        }

        visited.erase( c );
        p_m[ c ] = {};
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


        unordered_map< int, vector<int> > p_m;
        set<int> visited;

        for ( int i = 0; i <  numCourses; i++ ){
            p_m[ i ] =  {};
        }

        for ( auto & p : prerequisites ){
            p_m[ p[0] ].push_back( p[1] );
        }

        for (int c = 0; c < numCourses; c++){
            bool can_finish = dfs( p_m, visited, c );
            if ( !can_finish ) return false;
        }

        return true;
    }
};
