#leetcode 1334

// FLOYD WARSHALL

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> edge_mat(n, vector<int>(n, INT_MAX));
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int wt = edge[2];

            edge_mat[from][to] = wt;
            edge_mat[to][from] = wt;
            edge_mat[to][to] = 0;
            edge_mat[from][from] = 0;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (edge_mat[i][via] != INT_MAX &&
                        edge_mat[via][j] != INT_MAX &&
                        edge_mat[i][via] + edge_mat[via][j] < edge_mat[i][j]) {

                            edge_mat[i][j] = edge_mat[i][via] + edge_mat[via][j];
                    }
                }
            }
        }

        int min_neighbour_city = -1;
        int min_neighbour_count = INT_MAX;

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<edge_mat[i][j]<<" ";
        //     }

        //     cout<<endl;
        // }

        for(int i = 0; i<n; i++){
            
            int city_count = 0;
            for(int j=0; j<n; j++){
                if(edge_mat[i][j] <= distanceThreshold) city_count++;
            }

            if(city_count <= min_neighbour_count){
                min_neighbour_count = city_count;
                min_neighbour_city = i;
            }
        }

        return min_neighbour_city;
    }
};
