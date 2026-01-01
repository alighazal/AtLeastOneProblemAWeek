class Solution {
public:

    unordered_map<int, vector<int>> p_m;
    set<int> visited, cycle_path;
    vector<int> output;

    bool dfs(int course ){

        if ( cycle_path.find(course) != cycle_path.end() ) return false;
        if ( visited.find(course) != visited.end() ) return true;


        cycle_path.insert( course );

        for (auto & pr_course: p_m[course]){
            if ( ! dfs(pr_course) ){
                return false;
            }
        }

        cycle_path.erase( course );
        visited.insert( course );
        output.push_back( course );

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        for( auto & p :  prerequisites ){
            p_m[ p[0] ].push_back( p[1]  );
        }

        for (int course = 0; course < numCourses; course ++ ){
            if ( !dfs(course) ){
                return {};
            }
        }

        return output;

    }
};
