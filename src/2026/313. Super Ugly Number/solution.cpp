class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n);
        vector<int> indices(primes.size());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dp[0] = 1;
        for (int i = 0; i < primes.size(); i++){
            pq.push( {primes[i], i } );
        }

        for (int i = 1; i < n;){
            auto [val, index] = pq.top();
            pq.pop();
            if ( dp[i-1] != val ){
                dp[i++] = val;
            }
            indices[index]++;
            if (indices[index] < n && dp[indices[index]] != 0 &&
                primes[index] <= INT_MAX / dp[indices[index]]) {
                pq.push({primes[index] * dp[indices[index]], index});
            }
        }
        return dp.back();
    }
};
