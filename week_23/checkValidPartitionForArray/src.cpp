class Solution {
public:
    unordered_map<int,int> cache;
    bool dfs(vector<int>& nums, int i){

        if (i == nums.size()) return true;

        if (cache.find(i) != cache.end()) return  cache[i];

        bool res = false;
        if ( i < nums.size() - 1 && nums[i] == nums[i+1] ){
            res = dfs( nums, i + 2 );
        }
        if (i < nums.size() - 2 && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]){
            res |= dfs( nums, i + 3 );
        }
        if ( i < nums.size() - 2 && nums[i] == nums[i+1]-1 && nums[i+1] == nums[i+2]-1 ){
            res |= dfs( nums, i + 3 );
        }

        cache[i] = res;
        return res;
    }

    bool validPartition(vector<int>& nums) {
        return dfs(nums, 0);
    }
};

