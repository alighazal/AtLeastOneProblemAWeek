class Solution {
public:

    int solveByTwoCountersMethod( vector<int>& nums ){
        int ones = 0, twos = 0;

        for (auto & num: nums){
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }

    int solveByBitCounting( vector<int>& nums  ){
        int result = 0;
        for ( int j = 0; j < 32; j++ ){
            int mask = 1 << j;
            int count = 0;
            for (int i = 0; i < nums.size(); i++){
                count += ((nums[i] & mask) >> j);
            }
            if (count % 3 != 0){
                result |= mask;
            }
        }
        return result;
    }

    int singleNumber(vector<int>& nums) {

        return solveByTwoCountersMethod(nums);

    }
};
