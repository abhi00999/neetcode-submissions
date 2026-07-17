class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int suffixMax = prices[prices.size()-1];
        int cur, res = 0;

        for(int i = prices.size()-2; i>=0; i--){
            if(suffixMax > prices[i]){
                cur = suffixMax - prices[i]; 
                res = max(res, cur);
            }
            suffixMax = max(suffixMax, prices[i]);
        }
        return res;
    }
};
