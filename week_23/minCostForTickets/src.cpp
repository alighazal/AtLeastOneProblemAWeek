class Solution {
public:

    unordered_map<int,int> cache;

    int dfs(vector<int>& days, vector<int>& costs, int i){

        if (i >= days.size()) return 0;

        if (cache.find(i) != cache.end()) return cache[i];

        int res = INT_MAX;

        // buy 1 day ticket
        int next_i = i;
        while (next_i < days.size() && days[next_i] < days[i] + 1 ){
            next_i += 1;
        }
        res = min(res, dfs( days, costs, next_i ) + costs[0] );
        
        // buy 7 days ticket
        next_i = i;
        while (next_i < days.size() && days[next_i] < days[i] + 7 ){
            next_i += 1;
        }
        res = min(res, dfs( days, costs, next_i ) + costs[1] );

        // buy 30 days ticket
        next_i = i;
        while (next_i < days.size() && days[next_i] < days[i] + 30 ){
            next_i += 1;
        }
        res = min(res, dfs( days, costs, next_i ) + costs[2] );

        cache[i] = res;
        return res;

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return dfs(days, costs, 0);
    }
};
