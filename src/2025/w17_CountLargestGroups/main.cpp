class Solution {
public:

    int get_digits_sum(int num){
        int sum = 0;
        while (num){
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        vector<int> m(40, 0);
        int largest_group_size = -1;
        for (int i = 1; i <=n; i++){
            int sum = get_digits_sum( i );
            m[sum] ++;
            largest_group_size = max( largest_group_size, m[sum]);
        }

        int res = 0;
        for (auto & g : m){
            if (g == largest_group_size){
                res ++;
            }
        }
        return res;
    }
};
