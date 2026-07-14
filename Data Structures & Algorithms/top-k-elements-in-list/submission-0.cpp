class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(auto it: nums) mp[it]++;

        vector<vector<int>> vt;
        vector<int> res;

        for(auto it: mp) vt.push_back({it.second, it.first});

        sort(vt.begin(), vt.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] > b[0];  // assumes non-empty vectors
            });

        for(int i=0; i<k; i++) res.push_back(vt[i][1]);

        return res;
    }
};
