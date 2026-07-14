class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {0};
        for(auto it: s) cnt[it - 'a']++;
        for(auto it: t) cnt[it - 'a']--;

        for(auto it: cnt){
            if(it) return false;
        }
        return true;
    }
};
