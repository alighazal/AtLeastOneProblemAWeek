class Solution {
public:
    int jump(vector<int>& nums) {
    
        int res = 0;
        int left = 0, right = 0;

        while (right < nums.size() -1){
            int farthest = 0;
            for (int i = left; i <= right; i++){
                farthest = max(  farthest, nums[i] + i );
            }

            left = right;
            right = farthest;
            res += 1;
        }
        return res;

    }
};
