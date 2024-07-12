// https://leetcode.com/problems/merge-intervals/description/



#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

vector<vector<int>> merge_intervals(vector<vector<int>>& nums){
    sort(nums.begin() , nums.end());
    int n = nums.size();
    vector<vector<int>> output;

    output.push_back(nums[0]);
    
    for(int i=1; i<n; i++){
        vector<int> top = output.back();
    
        if(top[1] >= nums[i][0]){
            output.back()[1] = max(nums[i][1] , top[1]);
        }
        else{
            output.push_back(nums[i]);
        }
    }
    
    return output;

}

int main(){

}