class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res=0;
        for(auto it: nums) mp[it] = 1;
        for(auto it: mp){
            int cnt = 0;
            if(mp.count(it.first + 1) == 0){
                int cur = it.first;
                while(mp.count(cur)) {cnt++; mp[cur] = 0; cur--;}
            }
            res = max(res, cnt);
        }
        return res;
    }
};
