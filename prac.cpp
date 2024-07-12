class Solution {
public:
int bfs(vector<vector<int>>& mat , int row , int col){
    int n = mat.size();
    int m = mat[0].size();

    queue<pair<pair<int,int>,int>> pending;
    vector<vector<int>> visited(n , vector<int>(m,-1));
    pending.push(make_pair(make_pair(row,col),0));

    bool g = false;
    if(row == 2 && col == 0){
        g = true;
    }

    

    int min_dist = INT_MAX;

    while(!pending.empty()){
        pair<pair<int,int>,int> front = pending.front();
        int i = front.first.first;
        int j = front.first.second;
        int time = front.second;

        // cout<<row<<" "<<col<<endl;
        // cout<<time<<endl;

        if(mat[i][j] == 0){
           min_dist = time;
           break;
            
        }

        

        visited[i][j] = 1;

        pending.pop();

        // up
        if(i-1 >= 0 && visited[i-1][j] == -1){      
            pending.push(make_pair(make_pair(i-1,j),time+1));
            visited[i-1][j] = 1;
        }       

        // down
        if(i+1 < n && visited[i+1][j] == -1){
            pending.push(make_pair(make_pair(i+1,j),time+1));
            visited[i+1][j] = 1;
        }

        // right
        if(j+1 < m && visited[i][j+1] == -1){
            pending.push(make_pair(make_pair(i,j+1),time+1));
            visited[i][j+1] = 1;
        }

        // left
        if(j-1 >= 0 && visited[i][j-1] == -1){
            pending.push(make_pair(make_pair(i,j-1),time+1));
            visited[i][j-1] = 1;
        }

    }

    return min_dist;
}

vector<vector<int>> helper(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    
    vector<vector<int>> output(n , vector<int>(m,-1));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){
                output[i][j] = 0;
            }
            else{
                output[i][j] = bfs(mat,i,j);
            }
        }
    }

    return output;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return helper(mat);
    }
};