#include <string>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            int max_len = 0;
            bool exist[256];
            memset(exist, false, sizeof(exist));
            int n = s.size();
            int i = 0, j = 0;
            for (int i = 0; i < s.size(); i++) {
                    memset(exist, false, sizeof(exist));
                    for (int j = 0; j < s.size() - i; j++) {
                            if (exist[s.at(i + j)] != true) {
                                    exist[s.at(i + j)] = true;
                            } else {
                                    break;
                            }
                            if (j + 1 > max_len) {
                                    max_len = j + 1;
                            }
                    }
            }
            return max_len;
    }

    int lengthOfLongestSubstring_dp(string s) {

            vector<int> charIndex(256, -1);
            int longest = 0, m = 0;

            for (int i = 0; i < s.length(); i++) {
                    m = max(charIndex[s[i]] + 1, m);
                    charIndex[s[i]] = i;
                    longest = max(longest, i - m + 1);
            }

            return longest;
    }
};

int main() {
        string s = "abcabcbb";
        Solution so;
        int res = so.lengthOfLongestSubstring(s);
        cout << res << endl;
}