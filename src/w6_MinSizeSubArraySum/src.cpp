class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        if (nums.size() < 1) return 0;

        int l = 0;
        int sum = 0;
        int len = INT_MAX;
        for (int r = 0; r < nums.size(); r++){
            sum += nums[r];
            if (sum >= target){
                while(sum >= target ){
                    len = min( r - l + 1, len);
                    sum -= nums[l];
                    l++;
                }
            }
        }
        return  (len == INT_MAX)? 0: len;
    }
};
