#leetcode 2022

class Solution {
    bool isPalindrome(string &s, int mask) {
        vector<int> index;
        for (int i = 0; mask; mask >>= 1, ++i) {
            if (mask & 1) index.push_back(i);
        }
        for (int i = 0, j = index.size() - 1; i < j; ++i, --j) {
            if (s[index[i]] != s[index[j]]) return false;
        }
        return true;
    }
public:
    int maxProduct(string s) {
        int N = s.size();
        vector<int> dp(1 << N), pal(1 << N);
        for (int m = 1; m < 1 << N; ++m) {
            pal[m] = isPalindrome(s, m);
        }
        for (int m = 1; m < 1 << N; ++m) { // `m` is a subset of all the characters
            for (int sub = m; sub; sub = (sub - 1) & m) { // `sub` is a subset of `m`
                if (pal[sub]) dp[m] = max(dp[m], __builtin_popcount(sub)); // if this subset forms a palindrome, update the maximum length
            }
        }
        int ans = 0;
        for (int m = 1; m < 1 << N; ++m) {
            ans = max(ans, dp[m] * dp[(1 << N) - 1 - m]);
        }
        return ans;
    }
};
