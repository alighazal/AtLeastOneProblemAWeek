class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (auto & num : nums){
            pq.push( num );
        }

        while (k-- > 1 ){
            pq.pop();
        }

        return pq.top();
        
    }
};
