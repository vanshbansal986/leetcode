// https://leetcode.com/problems/longest-consecutive-sequence/description/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



void longestSeq(vector<vector<int>>& nums){
    int n = nums.size();
    int m = nums[0].size();
    unordered_map<int,int> map_row;
    unordered_map<int,int> map_col;


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(nums[i][j] == 0){
                map_row[i] = 1;
                map_col[j] = 1;
            }
        }
        
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // checking if corresponding column is zero
            if(map_row.count(i) > 0){
                nums[i][j] = 0;
            }
            if(map_col.count(j) > 0){
                nums[i][j] = 0;
            }
        }
        
    }

    

}

int main(){
    
    

}

