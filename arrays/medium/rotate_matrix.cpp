// https://leetcode.com/problems/rotate-image/description/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void swap(vector<vector<int>>& nums , int row1,int col1 , int row2 , int col2){
    int temp = nums[row1][col1];
    nums[row1][col1] = nums[row2][col2];
    nums[row2][col2] = temp;;

}



void longestSeq(vector<vector<int>>& nums){
    int n = nums.size();
    int m = nums[0].size();

    vector<vector<int>> visited(n , vector<int>(n,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j] == 0){
                int swap_ind = n-i-1;
                swap(nums,i,j,j,swap_ind);
                visited[i][j] = 1;
                visited[j][swap_ind] = 1;
            }
            
        }
        
    }
}

int main(){
    
    

}

