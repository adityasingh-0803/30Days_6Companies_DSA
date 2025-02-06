#leetcode 1686

class Solution {
public:
   int stoneGameVI(vector<int>& aV, vector<int>& bV) {
    vector<array<int, 3>> n;
    int a = 0, b = 0, sz = aV.size();
    for (int i = 0; i < sz; ++i)
        n.push_back({aV[i] + bV[i], aV[i], bV[i]});
    sort(begin(n), end(n));
    for (int i = 0; i < sz; ++i) {
        a += i % 2 ? 0 : n[sz - i - 1][1];
        b += i % 2 ? n[sz - i - 1][2] : 0;
    }
    return a == b ? 0 : a > b ? 1 : -1;
}
};
