#include <iostream>
#include <queue>
#include<vector>
using namespace std;


vector<vector<int>> adj_matrix(vector<vector<int>>& grid, int &count,vector<int> &start){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> output(m*n,vector<int>(m*n,-1) );
    vector<vector<int>> vertex(n,vector<int>(m,-1));

    int k = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(grid[i][j] == 1 || grid[i][j] == 2){
                vertex[i][j] = k;
                k++;
            }
        }
    }


    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(grid[i][j] == 2 || grid[i][j] == 1){
                count++;
                int v1 = vertex[i][j];
                int v2;

                if(grid[i][j] == 2){
                    start.push_back(v1);
                }

                // up
                if(i-1 >= 0 && grid[i-1][j] == 1){

                    v2 = vertex[i-1][j];
                    output[v1][v2] = 1;
                }

                // down
                if(i+1 < n && grid[i+1][j] == 1){
                    v2 = vertex[i+1][j];
                    output[v1][v2] = 1;
                }

                // right
                if(j+1 < m && grid[i][j+1] == 1){
                    v2 = vertex[i][j+1];
                    output[v1][v2] = 1;
                }

                // left
                if(j-1 >= 0 && grid[i][j-1] == 1){
                    v2 = vertex[i][j-1];
                    output[v1][v2] = 1;
                }
            }
        }
    }       


            
        

    return output;
}
    

    int bfs(vector<vector<int>> edges , vector<int> &start , int &count){
        int ans = 0;
        queue<int> pending;
        vector<int> visited(edges.size() , -1);
        while(!start.empty()){
            pending.push(start.front());
            start.pop_back();
        }

        pending.push(-1);

        while(!pending.empty()){
            int front = pending.front();
            pending.pop();

            if(front == -1 && pending.size() == 0){
                break;
            }

            if(front == -1){
                ans++;
                pending.push(-1);
                continue;
            }

            visited[front] = 1;
            // cout<<"front: "<<endl;
            // cout<<front<<" ";

            for(int i=0; i<edges.size(); i++){
                if(i == front){
                    continue;
                }

                if(edges[front][i] == 1 && visited[i] == -1){
                    pending.push(i);
                    //visited[i] = 1;
                }

            }

        }

        for(int i=0; i<count; i++){
            if(visited[i] == -1){
                ans = -1;
            }
        }
        

        return ans;
    }

    void print_matrix(vector<vector<int>> edges){
        int n = edges.size();
        int m = edges[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<< edges[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        vector<int> start;
        vector<vector<int>> edges = adj_matrix(grid,count,start);
        // cout<<"adj_list:"<<endl;
        // print_matrix(edges);
        // cout<<endl;
        return bfs(edges,start,count);
    }