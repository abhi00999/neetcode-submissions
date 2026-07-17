class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        map<char, int> freq;

        // Frequency of characters required from t
        for (char c : t)
            freq[c]++;

        int left = 0;
        int right = 0;

        // Number of distinct characters still not completely matched
        int remaining = freq.size();

        int minLen = INT_MAX;
        int start = -1;

        while (right < s.size()) {

            // Expand the window
            if (freq.find(s[right]) != freq.end()) {
                freq[s[right]]--;

                // Required count for this character has been satisfied
                if (freq[s[right]] == 0)
                    remaining--;
            }

            // Current window contains all characters
            while (remaining == 0) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Shrink the window
                if (freq.find(s[left]) != freq.end()) {
                    freq[s[left]]++;

                    // Window is now missing one required character
                    if (freq[s[left]] > 0)
                        remaining++;
                }

                left++;
            }

            right++;
        }

        if (start == -1)
            return "";

        return s.substr(start, minLen);
    }
};