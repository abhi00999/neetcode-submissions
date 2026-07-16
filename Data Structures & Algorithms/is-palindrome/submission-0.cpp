class Solution {
public:
    string clean(string s){
        string res;
        for (char c : s) {
            if ((c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9')) {
                res += tolower(c);
            }
        }
        return res;
    }
    bool isPalindrome(string s) {
        string cleaned = clean(s);

        int left = 0, right = cleaned.size()-1;
        while(left<right){
            if(cleaned[left] != cleaned[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
