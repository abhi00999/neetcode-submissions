class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fromLeft(n,1);
        vector<int> fromRight(n,1);
        vector<int> res(n);

        for(int i = 1; i < n; i++){
            fromLeft[i] = nums[i-1]*fromLeft[i-1];
            fromRight[n-i-1] = nums[n-i]*fromRight[n-i];
        }

        for(int i = 0; i<n; i++){
            res[i] = fromLeft[i]*fromRight[i];
        }
        return res;

    }
};
