class Solution {
public:

    void dfs(vector<vector<int>>& isConnected, int i, int pid  ){

        for (int j = 0; j < isConnected.size(); j++){
            if ( isConnected[i][j] == 1 ){
                isConnected[i][j] = pid;
                dfs(isConnected, j , pid );
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int pid = 2;
        for (int i = 0; i < isConnected.size(); i++){
            dfs( isConnected, i ,  pid );
            pid++;
        }
        
        set<int> pids{};
        for (int i = 0; i < isConnected.size(); i++){
            for (int j = 0; j < isConnected[i].size(); j++){
                pids.insert( isConnected[i][j] );
            }
        }

        if (pids.find(0) != pids.end()){
            pids.erase(0);
        }

        return pids.size() ;
    }
};
