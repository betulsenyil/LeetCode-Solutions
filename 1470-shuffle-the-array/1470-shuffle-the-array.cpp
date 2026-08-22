class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> results(2*n);
        
        for (int i=0; i<n; i++) {
            results[2*i] = nums[i];
            results[2*i+1] = nums[i+n];
        }
        return results;
    }
};
// solved :3