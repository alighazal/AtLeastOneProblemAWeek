class Solution {
public:

    vector<string> partitions; 
    vector<vector<string>> result; 

    bool is_pal(string& str){
        auto s = str.begin();
        auto e = str.end()-1;
        while( s < e ){
            if ( *s != *e){
                return false;
            }
            s++; e--;
        }
        return true;
    }

    void dfs( string &s ){

        if (s.empty()){
            result.push_back(partitions);
        }

        for (int i = 1; i <= s.length(); i++){
            auto part1 = s.substr(0, distance( s.begin(), s.begin()+i));
            auto part2 = s.substr(i, distance( s.begin()+i, s.end()));
            if ( is_pal (part1)){
                partitions.push_back(part1);
                dfs( part2 );
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(s);
        return result;
    }
};
