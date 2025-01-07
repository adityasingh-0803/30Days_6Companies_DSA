#leetcode 2976
class Solution {
public:
    long long minimumCost(string src, string tar, vector<char>& ori, vector<char>& chan, vector<int>& cost) {
        int n = ori.size();
        int m = src.size();

        vector<vector<long long>> dist(26,vector<long long>(26,1e9));
        for(int i = 0; i < 26; ++i)
            dist[i][i] = 0;

        for (int i = 0; i < n; ++i)
            dist[ori[i]-'a'][chan[i]-'a'] = min(dist[ori[i]-'a'][chan[i]-'a'], (long long)cost[i]);
        
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k] != 1e9 && dist[k][j] != 1e9)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        long long ans = 0;

        for(int i = 0; i < m; ++i){
            if(dist[src[i]-'a'][tar[i]-'a'] == 1e9)
                return -1;
            
            ans += dist[src[i]-'a'][tar[i]-'a'];
        }

        return ans;
    }
};
